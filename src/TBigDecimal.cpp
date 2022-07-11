/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** TBigDecimal
*/

#include "TBigDecimal.hpp"
#include "Utils.hpp"
#include <decimal/decimal>
#include <algorithm>

avm::TBigDecimal::TBigDecimal(std::string v)
{
    setValue(v);
}

avm::TBigDecimal::~TBigDecimal()
{
}

void avm::TBigDecimal::setValue(std::string v)
{
    this->negative = false;
    try {
        if (v.front() == '-') {
            this->negative = true;
            v = v.substr(1, v.length());
        }
        v = avm::Utils::removeTrailingZero(v);
        std::vector<std::string> values = avm::Utils::parseString(v, '.');
        this->integer = values.front();
        if (values.size() == 2) {
            this->decimal = values.back();
        }
        else if (values.size() > 2)
            throw Error("Invalid bigdecimal format: " + v);
        else 
            this->decimal = "";
        for (std::string str : values) {
            if (str.find_first_not_of("0123456789") != std::string::npos)
                throw Error("Invalid bigdecimal format: " + v); 
        }
    }
    catch (std::exception &e) {
        throw Error("Invalid bigdecimal format: " + v);
    }
}

avm::eOperandType avm::TBigDecimal::getType() const
{
    return (avm::BIGDECIMAL);
}

std::string avm::TBigDecimal::toString() const
{
    std::string str;

    if (!this->integer.compare("0") && (!this->decimal.compare("0") || !this->decimal.compare("")))
        return ("0");
    if (this->negative)
        str += '-';
    str += this->integer;
    if (this->decimal.compare("0") && this->decimal.compare("")) {
        str += '.';
        str += this->decimal;
    }
    return (str);
}

std::shared_ptr<avm::TBigDecimal> avm::TBigDecimal::add(const std::shared_ptr<avm::TBigDecimal> rhs)
{
    std::string rstrdec = rhs->decimal;
    std::string lstrdec = this->decimal;
    std::string result;
    int r = 0;

    std::string biggerdec;
    int smallLendec;
    std::string smalldec;
    if (avm::Utils::isBigger(lstrdec, rstrdec)) {
        biggerdec = lstrdec;
        smallLendec = rstrdec.length();
        smalldec = rstrdec;
    }
    else {
        biggerdec = rstrdec;
        smallLendec = lstrdec.length();
        smalldec = lstrdec;
    }
    int biglen = biggerdec.length();
    std::reverse(biggerdec.begin(), biggerdec.end());
    std::reverse(smalldec.begin(), smalldec.end());

    for (int i = 0; i < smallLendec; i++) {
        int c = biggerdec[biglen - smallLendec + i] + smalldec[i] - 96 + r;
        r = 0;
        if (c > 9) {
            r = 1;
            c -= 10;
        }
        result.push_back(c + 48);
    }

    std::reverse(result.begin(), result.end());
    for (int i = biglen - smallLendec - 1; i >=0; i--) {
        result.push_back(biggerdec[i]);
    }
    std::reverse(result.begin(), result.end());
    if (this->decimal.compare("") || rhs->decimal.compare(""))
        result.push_back('.');


    std::string rstr = rhs->integer;
    std::string lstr = this->integer;

    std::string bigger;
    int smallLen;
    if (avm::Utils::isBigger(lstr, rstr)) {
        bigger = lstr;
        smallLen = rstr.length();
    }
    else {
        bigger = rstr;
        smallLen = lstr.length();
    }
    std::reverse(rstr.begin(), rstr.end());
    std::reverse(lstr.begin(), lstr.end());
    std::reverse(bigger.begin(), bigger.end());

    for (int i = 0; i < smallLen; i++) {
        int c = lstr[i] + rstr[i] - 96 + r;
        r = 0;
        if (c > 9) {
            r = 1;
            c -= 10;
        }
        result.push_back(c + 48);
        std::string tmpp = result;
        std::reverse(tmpp.begin(), tmpp.end());
        
    }
    if (r == 1)
        bigger[smallLen] += 1;
    for (int i = smallLen; i < (int)bigger.length(); i++) {
        result.push_back(bigger[i]);
        std::string tmpp = result;
        std::reverse(tmpp.begin(), tmpp.end());
    }
    if (result.compare("0")) {
        if (rhs->negative && this->negative)
            result.push_back('-');
    }
    std::reverse(result.begin(), result.end());
    return std::make_shared<avm::TBigDecimal>(result);
}

std::shared_ptr<avm::TBigDecimal> avm::TBigDecimal::operator+(const std::shared_ptr<avm::TBigDecimal> rhs)
{
    return (this->add(rhs));
}