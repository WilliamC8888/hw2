#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> wordList;
    std::string temp;

    for (size_t i = 0; i < rawWords.size(); i++) {
        if (isalnum(rawWords[i])) {
            temp += rawWords[i];  
        } else {
            if (temp.length() >= 2) {
                wordList.insert(convToLower(temp));  
            }
            temp = "";  
        }
    }
    if (temp.length() >= 2) { 
        wordList.insert(convToLower(temp));
    }
    return wordList;

}
/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start

#include <algorithm> 
#include <cctype>
#include <locale>

// trim. Pulled updated version off the above web page because the one provided didnt work with my version of c++
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}


void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}


void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}