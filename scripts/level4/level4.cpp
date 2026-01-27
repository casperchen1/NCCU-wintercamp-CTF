#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <fstream>

using namespace std;

const char* filename = "key";
char content[] = {103,115,115,111,114,57,46,46,113,96,118,45,102,104,115,103,116,97,116,114,100,113,98,110,109,115,100,109,115,45,98,110,108,46,98,96,114,111,100,113,98,103,100,109,48,46,77,66,66,84,44,118,104,109,115,100,113,98,96,108,111,44,66,83,69,46,113,100,101,114,46,103,100,96,99,114,46,108,96,104,109,46,114,98,113,104,111,115,114,46,107,100,117,100,107,51,46,113,104,99,99,107,100,45,111,120,
 '\n'-1};
const string hint = "\n\n你成功找到了一個提示! 要打開這個箱子你必須偽造出一個鑰匙(key)\n";

int main(int argc, char* argv[]) {
    fstream file(filename);

    if(file) {
        cout << "成功打開箱子\n";
        rename(filename, "secret_note.txt");
        file.clear();
        for(auto& c : content) {
            c += 1;
        }
        file << "CONFIDENTIAL!!!\nDO NOT SHARE!!!\n";
        file << content;
        unlink(argv[0]); // Delete exec

        return 0;
    }

    cout << "箱子被鎖住了\n";
}
