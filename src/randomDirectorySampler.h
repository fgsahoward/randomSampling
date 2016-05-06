#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RandomDirectorySampler {
    private:
        vector<string> fileList;
        int sample_size;

        string GetRandomFile();

    public:
        int numFiles;
        RandomDirectorySampler(string directory, int sample_size);
        string GetRandomSample();
};
