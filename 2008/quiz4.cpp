#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string toLowerWord(const string &word)
{
    string res(word.length(), ' ');
    for (int i = 0; i < word.length(); i++) {
        char letter = word[i];
        if (isupper(letter))
            res[i] = tolower(letter);
        res[i] = letter;
    }
    return res;
}

int main()
{
    ifstream         inputFile("4.in");
    string           tmp;
    map<string, int> m;
    while (inputFile >> tmp) {
        string lower = toLowerWord(tmp);
        m[tmp]++;
    }

    for (auto &p : m) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}