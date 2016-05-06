#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "src/randomDirectorySampler.h"

using namespace std;

void bail(string msg);
vector<string> getNames(int argc, char * args[]);

int main(int argc, char * argv[]) {
    if (argc < 3)
        bail("Usage: <directory> <name> [name] [name...]");

    auto dirSampler = RandomDirectorySampler(argv[1], 1);
    cout << "Directory has " << dirSampler.numFiles << " files..." << endl;
    if (dirSampler.numFiles == 0)
        bail("Directory empty or failed to read!");
    auto output = dirSampler.GetRandomSample();

    auto names = getNames(argc, argv);

    auto scumMaster = names[((int)output[0]) % names.size()];

    cout << "Next Scrum Mater: " << scumMaster << endl;

    return 0;
}

void bail(string msg) {
    cout << msg << endl;
    exit(1);
}

vector<string> getNames(int argc, char * args[]) {
    auto names = vector<string>();

    for (auto i = 2; i < argc; i++)
        names.push_back(string(args[i]));

    return names;
}
