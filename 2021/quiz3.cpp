#include "../PerformanceMonitor/performance_monitor.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<pair<vector<uint>, string>> readTestCases(const string &filename)
{
    vector<pair<vector<uint>, string>> testCases;
    ifstream                           inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return testCases;
    }
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        uint          a, b, c, d;
        string        expected;

        if (iss >> a >> b >> c >> d >> expected) {
            testCases.push_back({{a, b, c, d}, expected});
        } else {
            cerr << "Warning: Invalid line format - " << line << endl;
        }
    }

    inputFile.close();
    return testCases;
}

class Solution
{
    vector<int> path;

  public:
    string could24game(const vector<uint> &cards)
    {
        auto nums = cards;
        sort(nums.begin(), nums.end());
        return backtracking(nums) ? "YES" : "NO";
    }

  private:
    bool backtracking(const vector<uint> &nums)
    {
        if (nums.size() == 1)
            return nums.front() == 24;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                vector<uint> combines;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        combines.push_back(nums[k]);
                }

                uint sum = nums[i] + nums[j];
                // 剪枝
                if (sum <= 24) {
                    combines.push_back(sum);
                    if (backtracking(combines))
                        return true;
                    combines.pop_back();
                }

                uint product = nums[i] * nums[j];
                if (product <= 24) {
                    combines.push_back(product);
                    if (backtracking(combines))
                        return true;
                    combines.pop_back();
                }
            }
        }

        return false;
    }
};

void batchRun()
{
    Solution           solution;
    PerformanceMonitor monitor;

    string filename  = "test_cases_quiz3.txt";
    auto   testCases = readTestCases(filename);

    int         fails = 0;
    vector<int> failedCasesNum;
    for (auto i = 0; i < testCases.size(); i++) {
        auto cards    = testCases[i].first;
        auto expected = testCases[i].second;

        monitor.start();
        auto actual = solution.could24game(cards);
        monitor.stop();

        if (actual == expected) {
            std::cout << "Test case " << i + 1 << " PASSED: a = " << cards[0]
                      << ", b = " << cards[1] << ", c = " << cards[2] << ", d = " << cards[3]
                      << ", expected = " << expected << ", actual = " << actual << std::endl;
        } else {
            failedCasesNum.push_back(i + 1);
            fails++;
            std::cout << "Test case " << i + 1 << " FAILED: a = " << cards[0]
                      << ", b = " << cards[1] << ", c = " << cards[2] << ", d = " << cards[3]
                      << ", expected = " << expected << ", actual = " << actual << std::endl;
        }
    }

    cout << "\nFAILS total: " << fails << ". Test case number are: ";
    for (auto f : failedCasesNum) {
        cout << f << " ";
    }
    cout << endl;
}

void run()
{
    Solution           solution;
    PerformanceMonitor monitor;
    cout << solution.could24game({1, 1, 1, 1}) << endl;
}

int main()
{
    batchRun();
    return 0;
}