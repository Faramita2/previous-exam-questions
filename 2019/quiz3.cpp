#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<pair<vector<string>, double>> readTestCases(string filename)
{
    vector<pair<vector<string>, double>> testCases;
    ifstream                             inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return testCases;
    }
    string line;

    while (getline(inputFile, line)) {
        istringstream  iss(line);
        vector<string> ops;

        string tmp;
        double expected;
        while (iss >> tmp) {
            ops.push_back(tmp);
        }
        expected = stod(ops.back());
        ops.pop_back();

        testCases.push_back({ops, expected});
    }

    return testCases;
}

class Solution
{
  public:
    double calculateFromPolishNotation(const vector<string> &exp)
    {
        stack<double> operand;
        for (int i = exp.size() - 1; i >= 0; i--) {
            size_t pos = 0;
            if (exp[i][0] == '-')
                pos++;
            if (exp[i].length() > 1 || isdigit(exp[i][pos]))
                operand.push(stoi(exp[i]));
            else {
                double a = operand.top();
                operand.pop();
                double b = operand.top();
                operand.pop();
                double res;
                string op = exp[i];

                if (op == "+")
                    res = a + b;
                else if (op == "-")
                    res = a - b;
                else if (op == "*")
                    res = a * b;
                else
                    res = a / b;

                operand.push(res);
            }
        }

        return operand.top();
    }
};

void batchRun()
{
    string      filename  = "pre.in";
    auto        testCases = readTestCases(filename);
    int         fails     = 0;
    vector<int> failNumbers;
    Solution    solution;

    for (int i = 0; i < testCases.size(); i++) {
        auto [ops, expected] = testCases[i];
        auto actual          = solution.calculateFromPolishNotation(ops);

        if (actual == expected) {
            std::cout << "Test case " << i + 1
                      << " PASSED, expected = " << expected
                      << ", actual = " << actual << std::endl;
        } else {
            fails++;
            failNumbers.push_back(i + 1);
            std::cout << "Test case " << i + 1
                      << " FAILED, expected = " << expected
                      << ", actual = " << actual << std::endl;
        }
    }
    cout << "\nFAILS total: " << fails << ". Test case number are: ";
    for (auto f : failNumbers) {
        cout << f << " ";
    }
    cout << endl;
}

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;
    vector<string>     exp1 = {"-", "+", "1", "*", "+", "2", "3", "4", "5"};
    vector<string>     exp2 = {"-", "/", "*", "+", "1", "2", "3", "4", "5"};

    cout << accumulate(
                next(exp1.begin()), exp1.end(), exp1[0],
                [](const string &a, const string &b) { return a + " " + b; })
         << " = " << solution.calculateFromPolishNotation(exp2) << endl;

    batchRun();

    return 0;
}