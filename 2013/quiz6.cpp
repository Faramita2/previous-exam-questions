#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int kmp(string &main, string &sub)
{
    int len1 = main.length(), len2 = sub.length();

    vector<int> next(len2, 0);
    for (int i = 1; i < len2; i++) {
        if (sub[i] == sub[next[i - 1]])
            next[i] = next[i - 1] + 1;
        else if (sub[i] == sub[0])
            next[i] = 1;
        else
            next[i] = 0;
    }
    for (int i = len2 - 1; i >= 1; i--) {
        next[i] = next[i - 1];
    }
    next[0] = -1;
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (main[i] == sub[j]) {
            i++;
            j++;
        } else {
            if (next[j] == -1)
                i++;
            else
                j = next[j];
        }
    }
    if (j == len2)
        return i - j;
    return -1;
}

int main()
{
    ifstream inputFile("6.in");
    ofstream outputFile("6.out");
    string   s1, s2;
    getline(inputFile, s1);
    getline(inputFile, s2);
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    // stl
    // int pos = s1.find(s2);
    // kmp
    int pos = kmp(s1, s2);
    if (pos == -1) {
        outputFile << 0;
    } else
        outputFile << pos + 1 << " " << pos + s2.size();

    return 0;
}