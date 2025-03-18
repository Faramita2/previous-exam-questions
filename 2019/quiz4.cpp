#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void print(vector<vector<char>> &subsets)
{
    cout << "{";
    bool flag1 = true;
    for (int i = 0; i < subsets.size(); i++) {
        if (!flag1)
            cout << ",";
        else
            flag1 = false;
        cout << "{";
        bool flag2 = true;
        for (int j = 0; j < subsets[i].size(); j++) {
            if (!flag2)
                cout << ",";
            else
                flag2 = false;
            cout << subsets[i][j];
        }
        cout << "}";
    }
    cout << "}" << endl;
}

void backtracking(vector<char> &chars, vector<vector<char>> &subsets,
                  int startIndex)
{
    if (startIndex == chars.size()) {
        print(subsets);
        return;
    }

    for (int i = 0; i < subsets.size(); i++) {
        subsets[i].push_back(chars[startIndex]);
        backtracking(chars, subsets, startIndex + 1);
        subsets[i].pop_back();
    }

    subsets.push_back({chars[startIndex]});
    backtracking(chars, subsets, startIndex + 1);
    subsets.pop_back();
}

int main()
{
    ifstream     inputFile("set.in");
    char         c;
    vector<char> chars;
    while (inputFile >> c) {
        chars.push_back(c);
    }
    vector<vector<char>> subsets;
    backtracking(chars, subsets, 0);

    return 0;
}