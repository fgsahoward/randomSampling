#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class RandomFileReader {
    private:
        ifstream fd;
        int size;

        int GetFileSize();
    public:
        RandomFileReader(string file);
        ~RandomFileReader();

        char GetRandomByte();
        string GetRandomSample(int max_size);
};
