#include <string>
#include <vector>

using namespace std;

class DirectoryReader {
    private:
        string dir;

    public:
        DirectoryReader(string dir);
        vector<string> GetFileList();
};
