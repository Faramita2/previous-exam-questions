#include <cassert>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    regex    pattern("abc*d?e");
    ifstream inputFile("3.txt");

    bool found = false;

    string line;
    while (getline(inputFile, line)) {
        if (regex_search(line, pattern)) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "找到abc*d?e匹配" << endl;
    } else {
        cout << "没有找到abc*d?e匹配" << endl;
    }

    return 0;
}