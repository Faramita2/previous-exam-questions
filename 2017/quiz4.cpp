#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& graph, int start, vector<bool>& visited, int skip) {
    visited[start] = true;
    for (int neighbor : graph[start]) {
        if (visited[neighbor] || neighbor == skip) continue;
        dfs(graph, neighbor, visited, skip);
    }
}

void findBreakPoint(vector<vector<int>>& graph) {
    int size = graph.size();
    for (int skip = 1; skip < size; skip++) {
        vector<bool> visited(size, false);
        int start = 1;
        while (start == skip) start++;
        dfs(graph, start, visited, skip);

        for (int i = 1; i < size; i++) {
            if (i == skip) continue;
            if (visited[i] == false) {
                cout << skip << endl;
                return;
            } 
        }
    }
    cout << "not exist" << endl;
}

int main() {
    ifstream inputFile("input4.txt");
    if (!inputFile.is_open()) {
        cerr << "ERROR" << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    vector<vector<int>> graph(n + 1, vector<int>{});
    int from, to;
    while (inputFile >> from >> to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    if (n == 1) {
        cout << "not exist" << endl;
    } else {
        findBreakPoint(graph);
    }

    return 0;
}