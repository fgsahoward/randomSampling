#include <iostream>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <vector>

#include "DirectoryReader.h"

using namespace std;

DirectoryReader::DirectoryReader(string dir) {
    this->dir = dir;
}

vector<string> DirectoryReader::GetFileList() {
    vector<string> files;
    auto directory = opendir(this->dir.c_str());
    struct dirent * ent;

    if (directory != NULL) {
        while ((ent = readdir(directory)) != NULL) {
            if (ent->d_type == DT_REG)
                files.push_back(this->dir + "/" + string(ent->d_name));
        }

        closedir(directory);
    } else {
        cout << "Failed to read directory: " << this->dir << endl;
    }

    return files;
}
