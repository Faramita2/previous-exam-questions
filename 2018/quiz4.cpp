#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int commonLongestSubsequenceLength(const string& str1, const string& str2) {
    int size1 = str1.length(), size2 = str2.length();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    for (int i = 1; i < size1 + 1; i++) {
        for (int j = 1; j < size2 + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max({dp[i][j - 1], dp[i - 1][j]});
        }
    }
    return dp[size1][size2];
}

int main() {
    ifstream inputFile("input4.txt");
    if (!inputFile.is_open()) {
        cerr << "ERROR" << endl;
    }
    string str1, str2;
    while (inputFile >> str1 >> str2) {
        cout << commonLongestSubsequenceLength(str1, str2) << endl;
    }

    return 0;
}