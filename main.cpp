#include <iostream>
#include <algorithm>
#include <cctype>

// trim from start (in place)
std::string::iterator findFirstLetter(std::string &s) {
    return std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    });
}

// trim from end (in place)
std::string::iterator findLastLetter(std::string &s) {
    return std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base();
}
std::string deleteWhitespaces(std::string &s) {
    std::string res(findFirstLetter(s),findLastLetter(s));
    return res;
}

int main() {
    std::string a = "\t\t\n this is example \tstring \t \n \t ";
    std::cout<<deleteWhitespaces(a);
}


