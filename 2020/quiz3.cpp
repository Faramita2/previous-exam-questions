#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    // "123", "456", "78", "782", "789"
    // 789 782 78 456 123
    // 789 78 782 456 123
    // "78978782456123"
    string maxCombinationNumber(vector<string> &nums)
    {
        string res = "";
        sort(nums.begin(), nums.end(), cmp2);
        for (auto a : nums)
            res += a;

        return res;
    }

    static bool cmp2(const string &l, const string &r)
    {
        return l + r > r + l;
    }

    static bool cmp(const string &l, const string &r)
    {
        int llen   = l.length();
        int rlen   = r.length();
        int maxlen = max(llen, rlen);

        // cout << "left: " << l << ", right: " << r << ", llen: " << llen
        //      << ", rlen: " << rlen << ", min len: " << maxlen << endl;

        for (int i = 0; i < maxlen; i++) {
            // 精华部分
            if (l[i % llen] == r[i % rlen])
                continue;
            return l[i % llen] > r[i % rlen];
        }

        return true;
    }
};

vector<pair<vector<string>, string>> readTestCases(const string &filename)
{
    vector<pair<vector<string>, string>> testCases;
    ifstream                             inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return testCases;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream  iss(line);
        string         tmp;
        vector<string> strings;
        while (iss >> tmp) {
            strings.push_back(tmp);
        }
        string expected = strings.back();
        strings.pop_back();
        testCases.push_back({strings, expected});
    }

    return testCases;
}

void batchRun()
{
    Solution           solution;
    PerformanceMonitor monitor;

    string                               filename  = "number.in";
    vector<pair<vector<string>, string>> testCases = readTestCases(filename);
    int                                  fails     = 0;
    vector<int>                          failsNum;
    for (int i = 0; i < testCases.size(); i++) {
        auto [nums, expected] = testCases[i];
        auto actual           = solution.maxCombinationNumber(nums);

        if (actual == expected) {
            cout << "Test case " << i + 1 << " PASSED." << endl;
        } else {
            failsNum.push_back(i + 1);
            fails++;
            cout << "Test case " << i + 1 << " FAILED, expected = " << expected
                 << ", actual = " << actual << endl;
        }
    }

    if (fails > 0) {
        cout << "FAILED Test Case: ";
        for (auto i : failsNum) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Solution           solution;
    // PerformanceMonitor monitor;

    // vector<string> nums1 = {"123", "456", "78", "782", "789"};
    // cout << solution.maxCombinationNumber(nums1) << endl;

    batchRun();

    return 0;
}