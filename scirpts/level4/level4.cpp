#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <fstream>

using namespace std;

const char* filename = "REAL_KEY";
char content[] = {83, 103, 104, 114, 31, 104, 114, 31, 96, 31, 115, 100, 114, 115, 45, '\0'};
const string hint = "\n\nYou've found a hint! Create a file named \'REAL_KEY\' to open the box.\n\n";

int main(int argc, char* argv[]) {
    fstream file(filename);

    if(file) {
        cout << "The box is opened.\n";
        rename(filename, "note.txt");
        file.clear();
        for(auto& c : content) {
            c += 1;
        }
        file << content;
        unlink(argv[0]); // Delete exec

        return 0;
    }

    cout << "The box is locked.\n";
}
