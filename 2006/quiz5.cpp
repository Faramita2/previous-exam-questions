#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

ifstream            inputFile("graph.in");
ofstream            outputFile("graph.out");
vector<vector<int>> graph;
vector<bool>        visited;
int                 n, k;
int                 maxNodeCount = 0;
vector<int>         indexes;

void getMaxNodes(int i, int &curNodeCount)
{
    if (visited[i])
        return;
    visited[i] = true;
    curNodeCount++;
    maxNodeCount = max(curNodeCount, maxNodeCount);

    for (int j = 0; j < n; j++) {
        if (i == j || graph[i][j] == 0 || visited[j])
            continue;
        getMaxNodes(j, curNodeCount);
    }
}

void dfs(int i, int &curNodeCount)
{
    if (visited[i])
        return;
    visited[i] = true;
    curNodeCount++;
    if (curNodeCount == maxNodeCount) {
        indexes.push_back(i);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (i == j || graph[i][j] == 0 || visited[j])
            continue;
        dfs(j, curNodeCount);
    }
}

void print(int i, bool &isFirst)
{
    if (visited[i])
        return;

    if (!isFirst) {
        outputFile << " ";
    }
    outputFile << i;
    visited[i] = true;
    isFirst    = false;

    for (int j = 0; j < n; j++) {
        if (i == j || graph[i][j] == 0 || visited[j])
            continue;
        print(j, isFirst);
    }
}

int main()
{

    inputFile >> n >> k;
    graph   = vector<vector<int>>(n, vector<int>(n, 0));
    visited = vector<bool>(n, false);
    int from, to;
    for (int i = 0; i < k; i++) {
        inputFile >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    // calculate max nodes
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        int curNodeCount = 0;
        getMaxNodes(i, curNodeCount);
    }

    // find starts
    visited = vector<bool>(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        int curNodeCount = 0;
        dfs(i, curNodeCount);
    }

    // print all
    visited = vector<bool>(n, false);
    for (int index : indexes) {
        if (visited[index])
            continue;
        bool isFirst = true;
        print(index, isFirst);
    }

    return 0;
}