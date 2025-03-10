#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void solve(string str1, string str2)
{
    cout << "str1: " << str1 << ", str2: " << str2 << endl;
    int                 m = str1.length();
    int                 n = str2.length();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (auto &v : dp) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << dp[m - 1][n - 1] << endl;
}

int main()
{
    ifstream inputFile("input4.txt");
    string   line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string       str1, str2;
        ss >> str1 >> str2;

        solve(str1, str2);
    }

    return 0;
}