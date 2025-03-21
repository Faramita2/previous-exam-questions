#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> getNext(string& sub) {
    int len = sub.length();
    vector<int> next(len);
    next[0] = -1;
    int j = -1;
    for (int i = 1; i < len; i++) {
        while (j != -1 && sub[i] != sub[j + 1]) {
            j = next[j - 1];
        }
        if (sub[i] == sub[j + 1]) j++;
        next[i] = j;
    }
    return next;
}

int kmp(string &str, string &sub)
{
    vector<int> next = getNext(sub);

    int n = str.length();
    int m = sub.length();
    int i = 0, j = 0;
    while (i < n) {
        if (j == -1 || str[i] == sub[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
        if (j == m) {
            return i - j;
        }
    }
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