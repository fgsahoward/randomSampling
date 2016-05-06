#include <iostream>
#include <string>
#include <fstream>

#include "randomFileReader.h"

using namespace std;

RandomFileReader::RandomFileReader(string file) {
    this->fd.open(file, ifstream::binary);
    this->size = this->GetFileSize();
}

RandomFileReader::~RandomFileReader() {
    this->fd.close();
}

int RandomFileReader::GetFileSize() {
    auto orignalLocation = this->fd.tellg();

    this->fd.seekg(0, this->fd.end);
    auto fileSize = this->fd.tellg();

    this->fd.seekg(orignalLocation, this->fd.beg);
    return fileSize;
}

char RandomFileReader::GetRandomByte() {
    auto location = rand() % this->size;
    this->fd.seekg(location, this->fd.beg);

    char randomByte;
    this->fd >> randomByte;

    return randomByte;
}

string RandomFileReader::GetRandomSample(int max_size) {
    if (max_size <= 0)
        return string("");

    auto sampleSize = (rand() % max_size) + 1;
    char sample[sampleSize];

    for (int i=0; i<sampleSize; i++)
        sample[i] = this->GetRandomByte();

    return string(sample);
}
