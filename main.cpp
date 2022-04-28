#include <iostream>
#include <algorithm>
#include <cctype>

// trim from start (in place)
std::string::iterator findFirstLetter(std::string &s) {
    return std::find_if(s.begin(), s.end(), [](char ch) {
        return !std::isspace(ch);
    });
}

// trim from end (in place)
std::string::iterator findLastLetter(std::string &s) {
    return std::find_if(s.rbegin(), s.rend(), [](char ch) {
        return !std::isspace(ch);
    }).base();
}
std::string deleteWhitespaces(std::string &s) {
    auto firstCharacter=findFirstLetter(s);
    auto lastCharacter=findLastLetter(s);
    if (firstCharacter<lastCharacter)//when there is no letter problem may occur
        return std::string(findFirstLetter(s),findLastLetter(s));
    return "";
}

int main() {
    std::string a = "\t\t\n this is example \tstring \t \n \t ";
    std::string b = "\t\t\n \t \n \t ";

    std::cout<<deleteWhitespaces(a);
    std::cout<<deleteWhitespaces(b);
}


