#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// (1) 递归定义
// 假设我们已经知道如何对一个大小为 n−1 的集合进行划分，那么对于大小为 n
// 的集合：

// 将第 n 个元素加入到现有的每个子集中。
// 或者，将第 n 个元素单独作为一个新的子集。
// (2) 示例
// 以集合 {a, b, c} 为例：

// 对于 {a}，只有唯一划分：{{a}}。
// 加入 b：
// 将 b 加入现有子集：{{a, b}}。
// 将 b 单独成一个子集：{{a}, {b}}。
// 加入 c：
// 对于划分 {{a, b}}：
// 将 c 加入现有子集：{{a, b, c}}。
// 将 c 单独成一个子集：{{a, b}, {c}}。
// 对于划分 {{a}, {b}}：
// 将 c 加入第一个子集：{{a, c}, {b}}。
// 将 c 加入第二个子集：{{a}, {b, c}}。
// 将 c 单独成一个子集：{{a}, {b}, {c}}。
// 通过这种方式，可以递归地生成所有划分。
class Solution
{
  private:
    void print(const vector<vector<string>> &partition)
    {
        cout << "{";
        for (auto i = 0; i < partition.size(); i++) {
            cout << "{";
            for (auto j = 0; j < partition[i].size(); j++) {
                cout << partition[i][j];
                if (j != partition[i].size() - 1)
                    cout << ",";
            }
            cout << "}";
            if (i != partition.size() - 1)
                cout << ",";
        }
        cout << "}" << endl;
    }

  public:
    void solve(const vector<string> &elements, int startIndex,
               vector<vector<string>> &currentPartition)
    {
        if (startIndex == elements.size()) {
            print(currentPartition);
            return;
        }

        for (int i = 0; i < currentPartition.size(); i++) {
            currentPartition[i].push_back(elements[startIndex]);
            solve(elements, startIndex + 1, currentPartition);
            currentPartition[i].pop_back();
        }

        currentPartition.push_back({elements[startIndex]});
        solve(elements, startIndex + 1, currentPartition);
        currentPartition.pop_back();
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    ifstream       inputFile("set.in");
    vector<string> elements;
    string         element;
    while (inputFile >> element) {
        elements.push_back(element);
    }
    inputFile.close();

    vector<vector<string>> currentPartition;
    solution.solve(elements, 0, currentPartition);

    return 0;
}