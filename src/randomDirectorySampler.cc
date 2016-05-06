#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include <unistd.h>

#include "randomDirectorySampler.h"
#include "randomFileReader.h"
#include "directoryReader.h"

using namespace std;

RandomDirectorySampler::RandomDirectorySampler(string directory, int sample_size) {
    this->sample_size = sample_size;

    auto dirReader = DirectoryReader(directory);
    this->fileList = dirReader.GetFileList();

    this->numFiles = this->fileList.size();

    srand(time(NULL));
}

string RandomDirectorySampler::GetRandomSample() {
    string ret = "";

    while (ret.size() < this->sample_size) {
        auto fileName = this->GetRandomFile();
        RandomFileReader fr (fileName);
        ret += fr.GetRandomSample((this->sample_size - ret.size()) % rand() + 1);
    }

    return ret;
}

string RandomDirectorySampler::GetRandomFile() {
    auto it = this->fileList.begin();
    auto index = rand() % this->fileList.size();

    it += index;

    return *it;
}
