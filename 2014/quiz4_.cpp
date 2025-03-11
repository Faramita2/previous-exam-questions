#include <cassert>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("graph.in");
    if (!inputFile.is_open()) {
        cerr << "Error: cannot open graph.in." << endl;
        return 1;
    }

    int n; // 节点数
    inputFile >> n;
    inputFile.ignore(); // 忽略换行符

    // 使用邻接表存储图
    vector<vector<int>> graph(n + 1);

    // 读取边信息
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int           from, to;
        iss >> from >> to;
        if (from == 0 && to == 0)
            break;

        // 检查输入合法性
        if (from < 1 || from > n || to < 1 || to > n) {
            cerr << "Invalid edge: (" << from << ", " << to << ")" << endl;
            return 1;
        }

        // 添加无向边
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // BFS 遍历
    vector<bool> visited(n + 1, false);
    queue<int>   next;
    next.push(1); // 从节点 1 开始
    visited[1] = true;

    // 用于控制输出格式
    ostringstream output;

    while (!next.empty()) {
        int cur = next.front();
        next.pop();

        // 输出当前节点
        output << cur;

        // 遍历邻居节点
        for (int neighbor : graph[cur]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                next.push(neighbor);
                output << " "; // 添加空格
            }
        }
    }

    // 输出最终结果
    cout << output.str() << endl;

    return 0;
}