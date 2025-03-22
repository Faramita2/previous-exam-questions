#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main()
{
    regex    pattern("abc*d?e");
    ifstream inputFile("3.txt");

    bool found = false;

    string line;
    smatch baseMatch;
    while (getline(inputFile, line)) {
        if (regex_search(line, baseMatch, pattern)) {
            for (auto b : baseMatch) {
                cout << "base match: " << b.str() << endl;
            }
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