#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Graph
{
    int                 vNums;
    int                 eNums;
    vector<vector<int>> matrix;
};

void dfs(Graph &g, vector<bool> &visited, int start, int skip)
{
    if (visited[start])
        return;
    visited[start] = true;
    for (int j = 0; j < g.vNums; j++) {
        if (g.matrix[start][j] == 1 && j != skip && !visited[j]) {
            dfs(g, visited, j, skip);
        }
    }
}

void findVertex(Graph &g)
{
    for (int skip = 0; skip < g.vNums; skip++) {
        vector<bool> visited(g.vNums, false);
        dfs(g, visited, 0, skip);
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i] && i != skip) {
                cout << skip + 1 << endl;
                return;
            }
        }
    }
}

int main()
{
    Graph    g;
    ifstream inputFile("input4.txt");
    string   line;

    getline(inputFile, line);
    g.vNums  = stoi(line);
    g.matrix = vector<vector<int>>(g.vNums, vector<int>(g.vNums, 0));
    g.eNums  = 0;
    while (getline(inputFile, line)) {
        int          first, second;
        stringstream ss(line);
        ss >> first >> second;

        if (g.matrix[first - 1][second - 1] == 0) {
            g.eNums++;
        }

        g.matrix[first - 1][second - 1] = 1;
        g.matrix[second - 1][first - 1] = 1;
    }

    for (auto &v : g.matrix) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    findVertex(g);

    return 0;
}