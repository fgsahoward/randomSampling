#include <iostream>
#include <string>
#include <map>

#include "asciiFormatter.h"

using namespace std;

ASCIIFormatter::ASCIIFormatter(map<char, string> escaped) {
    escapedCharacters = escaped;
}

ASCIIFormatter::ASCIIFormatter() {
    auto disallowed = string("'\"()\\;!`");
    escapedCharacters = map<char, string>();
    
    for (auto curr = disallowed.begin(); curr != disallowed.end(); curr++) {
        escapedCharacters[*curr] = string("\\") + *curr;
    }
}

string ASCIIFormatter::Format(string input) {
    auto output = string("");
    auto offset = maxValue - minValue;

    for (auto it = input.begin(); it != input.end(); it++) {
        auto integerValue = (unsigned int) *it;
        auto asciiValue = (integerValue % offset) + minValue;

        if (escapedCharacters.count((char)asciiValue))
            output += escapedCharacters[(char)asciiValue];
        else
            output += (char)asciiValue;
    }

    return output;
}
