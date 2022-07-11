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
    for (int i = smallLen; i < (int)bigger.length(); i++) {
        if (r != 1)
            break;
        char c = bigger[i] + 1;
        if (c > '9')
            c -= 10;
        else
            r = 0;
        bigger[i] = c;
    }
    if (r == 1)
        bigger = bigger + "1";
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

std::shared_ptr<avm::TBigDecimal> avm::TBigDecimal::sub(const std::shared_ptr<avm::TBigDecimal> rhs)
{
    int r = 0;



    bool neg = false;
    std::string result;




    std::string rstr = rhs->decimal;
    std::string lstr = this->decimal;


    std::string bigger;
    int smallLen;
    std::string smaller;
    if (avm::Utils::isBigger(lstr, rstr)) {
        bigger = lstr;
        smaller = rstr;
        smallLen = rstr.length();
    }
    else {
        bigger = rstr;
        smaller = lstr;
        smallLen = lstr.length();
    }

    std::reverse(lstr.begin(), lstr.end());



     for (int i = 0; i < (int)bigger.length() - smallLen; i++) {
        smaller.push_back('0');
    }
    if (!avm::Utils::isBigger(this->decimal, rhs->decimal) ||  this->decimal.length() != rhs->decimal.length() || !avm::Utils::isBigger(this->integer, rhs->integer)) {
        std::string tx = bigger;
        bigger = smaller;
        smaller = tx;
    }
    std::reverse(bigger.begin(), bigger.end());
    std::reverse(smaller.begin(), smaller.end());
    for (int i = 0; i < (int)bigger.length(); i++) {
        int c = bigger[i] - smaller[i] - r;
        r = 0;
        if (c < 0) {
            r = 1;
            c += 10;
        }
        result.push_back(c + 48);
        
    }


    if (this->decimal.compare("") || rhs->decimal.compare(""))
        result.push_back('.');




    rstr = rhs->integer;
    lstr = this->integer;

    if (avm::Utils::isBigger(lstr, rstr)) {
        bigger = lstr;
        smaller = rstr;
        smallLen = rstr.length();
        neg = this->negative;
    }
    else {
        bigger = rstr;
        smaller = lstr;
        smallLen = lstr.length();
        neg = !rhs->negative;
    }


    std::reverse(smaller.begin(), smaller.end());
    std::reverse(lstr.begin(), lstr.end());



     for (int i = 0; i < (int)bigger.length() - smallLen; i++) {
        smaller.push_back('0');
    }
    std::reverse(bigger.begin(), bigger.end());
    for (int i = 0; i < (int)bigger.length(); i++) {
        int c = bigger[i] - smaller[i] - r;
        r = 0;
        if (c < 0) {
            r = 1;
            c += 10;
        }
        result.push_back(c + 48);
        
    }
    if (result.compare("0")) {
        if (neg)
            result.push_back('-');
    }
    std::reverse(result.begin(), result.end());
    return std::make_shared<avm::TBigDecimal>(result);
}

std::shared_ptr<avm::TBigDecimal> avm::TBigDecimal::mul(const std::shared_ptr<avm::TBigDecimal> rhs)
{
    std::string result;
    std::string lstr = this->integer + this->decimal;
    std::string rstr = rhs->integer + rhs->decimal;
    std::vector<std::string> list;

    int tmp = 0;

    for (int i = 0; i < (int)lstr.length(); i++) {
        std::string line;
        char c;
        for (int j = 0; j< i; j++)
            line += '0';
        for (int j = 0; j < (int)rstr.length(); j++) {
            c = (rstr[j] - 48) * (lstr[i] - 48) + tmp;
            if (c > 10) {
                tmp = c / 10;
                c = c % 10;
            }
            line.push_back(c + 48);
        }
        for (int j = i; j < (int)lstr.length() - 1; j++)
            line += '0';
        list.push_back(line);
    }
    if (tmp != 0) {
        std::string ret = std::string(1, tmp + 48);
        for (int i = 0; i < (int)(this->decimal.length() + rhs->decimal.length()); i++)
            ret += '0';
        list.push_back(ret);

    }
    auto o = std::make_shared<avm::TBigDecimal>("0");
    for (std::string str : list) {
        o = *o + std::make_shared<avm::TBigDecimal>(str);
    }
    std::string r = o->toString();
    if (!this->decimal.empty() || !rhs->decimal.empty())
        r.insert(r.length() - this->decimal.length() - rhs->decimal.length(), ".");
    o = std::make_shared<avm::TBigDecimal>(r);
    if (this->negative != rhs->negative)
        o->negative = true;
    else 
        o->negative = false;
    return o;
}

std::shared_ptr<avm::TBigDecimal> avm::TBigDecimal::operator+(const std::shared_ptr<avm::TBigDecimal> rhs)
{
    if (this->negative == rhs->negative)
        return (this->add(rhs));
    return (this->sub(rhs));
}

std::shared_ptr<avm::TBigDecimal> avm::TBigDecimal::operator-(const std::shared_ptr<avm::TBigDecimal> rhs)
{
    if (this->negative == rhs->negative)
        return (this->sub(rhs));
    rhs->negative = true;
    return (this->add(rhs));
}

std::shared_ptr<avm::TBigDecimal> avm::TBigDecimal::operator*(const std::shared_ptr<avm::TBigDecimal> rhs)
{
    return (this->mul(rhs));
}