#include <iostream>
#include <string>
#include <map>

using namespace std;

class ASCIIFormatter {
    private:
        map<char, string> escapedCharacters;
        int maxValue = (int)'~';
        int minValue = (int)' ';

    public:
        ASCIIFormatter();
        ASCIIFormatter(map<char, string> escaped);
        string Format(string input);
};
