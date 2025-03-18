#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input3.txt");
    if (!inputFile.is_open()) {
        cerr << "ERROR" << endl;
        return 1;
    }
    int m, n;
    inputFile >> m >> n;
    vector<int> stamps(n, 0);
    for (int i = 0; i < n; i++) {
        inputFile >> stamps[i];
    }
    vector<int> dp(m + 1, INT32_MAX);
    dp[0] = 0;
    for (int stamp : stamps) {
        for (int j = stamp; j < m + 1; j++) {
            if (dp[j-stamp] != INT32_MAX) {
                dp[j] = min(dp[j], dp[j - stamp] + 1);
            }
        }
    }
    cout << (dp.back() == INT32_MAX ? 0 : dp.back()) << endl;

    return 0;
}