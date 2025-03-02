#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<uint64_t>> readTestCases(const string &filename)
{
    vector<vector<uint64_t>> testCases;
    ifstream                 inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return testCases;
    }
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        uint64_t      a, b, expected;

        if (iss >> a >> b >> expected) {
            testCases.push_back({a, b, expected});
        } else {
            cerr << "Warning: Invalid line format - " << line << endl;
        }
    }

    inputFile.close();
    return testCases;
}

// 核心思路 ：
// 使用异或操作快速标记不同位。
// 统计异或结果中二进制 1 的个数。
// 注意事项 ：
// 数据类型选择：优先使用 uint64_t，避免负数和溢出问题。
// 高效实现：使用位运算和内置函数优化性能。
// 边界情况：测试特殊值（如 0、-1、最大值等）。
// 扩展思考 ：
// 如果需要支持更大的整数（如 128 位），可以使用 __int128 或其他大整数库。
// 如果输入数据量较大，可以考虑批量处理和多线程优化。
int calculate(uint64_t a, uint64_t b)
{
    uint64_t c        = static_cast<uint64_t>(a ^ b);
    int      distance = 0;
    while (c != 0) {
        distance += c & 1;
        c >>= 1;
    }
    return distance;
}

int main()
{
    // int64_t a, b;
    // Standard input
    // cin >> a >> b;
    // cout << calculate(a, b) << endl;

    string                   filename  = "test_cases_quiz2.txt";
    vector<vector<uint64_t>> testCases = readTestCases(filename);

    for (auto i = 0; i < testCases.size(); i++) {
        uint64_t a = testCases[i][0], b = testCases[i][1], expected = testCases[i][2];

        auto actual = calculate(a, b);

        if (actual == expected) {
            std::cout << "Test case " << i + 1 << " passed: a = " << a << ", b = " << b
                      << ", expected = " << expected << ", actual = " << actual << std::endl;
        } else {
            std::cout << "Test case " << i + 1 << " FAILED: a = " << a << ", b = " << b
                      << ", expected = " << expected << ", actual = " << actual << std::endl;
        }
    }

    return 0;
}