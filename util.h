#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
 //returns set of elements in both sets
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> endSet; 
    typename std::set<T>::iterator a = s1.begin();
    typename std::set<T>::iterator b = s2.begin();
    
    //goes through both at once
    while (a != s1.end() && b != s2.end()) {
        if (*a < *b) { //These two update the index of where we are in each input set
            ++a; 
        } else if (*b < *a) {
            ++b; 
        } else {
            endSet.insert(*a); 
            ++a;
            ++b;
        }
    }
    return endSet;

}

//set of elements in both input sets
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> endSet = s1; 
    endSet.insert(s2.begin(), s2.end());
    return endSet;

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
void ltrim(std::string &s) ;

// Removes any trailing whitespace
void rtrim(std::string &s) ;

// Removes leading and trailing whitespace
void trim(std::string &s) ;
#endif
