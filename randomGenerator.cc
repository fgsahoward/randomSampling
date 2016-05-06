#include <iostream>
#include <string>
#include <stdlib.h>

#include "src/randomDirectorySampler.h"
#include "src/asciiFormatter.h"

using namespace std;

void bail(string msg);

int main(int argc, char * argv[]) {
    if (argc != 3)
        bail("Usage: <directory> <sample_size>");

    auto dirSampler = RandomDirectorySampler(argv[1], atoi(argv[2]));
    cout << "Directory has " << dirSampler.numFiles << " files..." << endl;
    if (dirSampler.numFiles == 0)
        bail("Directory empty or failed to read!");
    auto output = dirSampler.GetRandomSample();

    auto formatter = ASCIIFormatter();
    auto formattedOutput = formatter.Format(output);

    cout << formattedOutput << endl;

    return 0;
}

void bail(string msg) {
    cout << msg << endl;
    exit(1);
}

