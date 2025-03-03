#include "../PerformanceMonitor/performance_monitor.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<pair<uint, string>> readTestCases(const string &filename)
{
    vector<pair<uint, string>> testCases;
    ifstream                   inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return testCases;
    }
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        uint          a;
        string        expected;

        if (iss >> a >> expected) {
            testCases.push_back({a, expected});
        } else {
            cerr << "Warning: Invalid line format - " << line << endl;
        }
    }

    inputFile.close();
    return testCases;
}

class Solution
{
  public:
    string to7digits(uint num)
    {
        if (num == 0)
            return "0";
        string res = "";
        while (num > 0) {
            res += string(1, num % 7 + '0');
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void batchRun()
{
    Solution           solution;
    PerformanceMonitor monitor;

    string filename  = "test_cases_quiz4.txt";
    auto   testCases = readTestCases(filename);

    int         fails = 0;
    vector<int> failedCasesNum;
    for (auto i = 0; i < testCases.size(); i++) {
        auto num      = testCases[i].first;
        auto expected = testCases[i].second;

        monitor.start();
        auto actual = solution.to7digits(num);
        monitor.stop();

        if (actual == expected) {
            std::cout << "Test case " << i + 1 << " PASSED: num = " << num
                      << ", expected = " << expected << ", actual = " << actual << std::endl;
        } else {
            failedCasesNum.push_back(i + 1);
            fails++;
            std::cout << "Test case " << i + 1 << " FAILED: num = " << num
                      << ", expected = " << expected << ", actual = " << actual << std::endl;
        }
    }

    cout << "\nFAILS total: " << fails << (fails == 0 ? "." : ". Test case number are: ");
    for (auto f : failedCasesNum) {
        cout << f << " ";
    }
    cout << endl;
}

int main()
{
    // Solution           solution;
    // PerformanceMonitor monitor;

    // cout << solution.to7digits(10) << endl;

    batchRun();

    return 0;
}