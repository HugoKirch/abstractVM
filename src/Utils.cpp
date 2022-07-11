/*
** EPITECH PROJECT, 2022
** B-SYN-400-NCY-4-1-abstractVM-hugo.kirch
** File description:
** Utils
*/

#include "Utils.hpp"
#include "Error.hpp"
#include <algorithm>

std::vector<std::string> avm::Utils::parseString(std::string line, char separator)
{

    std::vector<std::string> result;
    std::istringstream iss(line);
    std::string tmp;

    while(std::getline(iss, tmp, separator)) {
        if (!tmp.empty() || separator == ';' || separator == '.')
            result.push_back(tmp);
    }
    return (result);
}

std::string avm::Utils::removeTrailingZero(std::string str)
{
    size_t count = std::count_if(str.begin(), str.end(), []( char c ){return c =='.';});
    if (count  > 1 || str.back() == '.')
        throw Error("Invalid decimal format: " + str);
    if (str.find('.') == std::string::npos)
        return (str);
    str.erase(str.find_last_not_of('0') + 1, std::string::npos );
    if (str.back() == '.') {
        try {
            return (str.substr(0, str.length() - 1));
        }
        catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    return (str);
}

bool avm::Utils::isBigger(std::string lstr, std::string rstr)
{
    if (rstr.length() < lstr.length())
        return (true);
    else if (rstr.length() > lstr.length())
        return (false);
    if (lstr.compare(rstr) >= 0)
        return (true);
    return (false);
}