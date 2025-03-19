#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print(vector<char>& path, int& order) {
    bool isFirst = true;
    cout << "第" << ++order << "种组合: ";
    for (char c : path) {
        if (!isFirst) cout << ",";
        isFirst = false;
        cout << c;
    }
    cout << endl;
}

void backtracking(const string& s, vector<char>& path, int startIndex, int& order) {
    if (path.size() == 5) {
        print(path, order);
        return;
    }

    int len = s.length();
    for (int i = startIndex; i < len; i++) {
        path.push_back(s[i]);
        backtracking(s, path, i + 1, order);
        path.pop_back();
    }
}

int main() {

    vector<char> path;
    int order = 0;
    const string s = "abcdefghij";
    backtracking(s, path, 0, order);

    return 0;
}