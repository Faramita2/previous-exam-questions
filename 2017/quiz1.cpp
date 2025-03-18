#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input1.txt");
    if (!inputFile.is_open()) {
        cerr << "ERROR" << endl;
        return 1;
    }

    string tmp;
    bool flag = false;
    while (inputFile >> tmp) {
        if (flag) {
            cout << " ";
        }
        flag = true;
        tmp[0] = toupper(tmp[0]);
        cout << tmp;
    }

    return 0;
}