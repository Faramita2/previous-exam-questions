#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, size_t start, vector<size_t>& component) {
    component.push_back(start);
    visited[start] = true;
    for (size_t i = 0; i < graph.size(); i++) {
        if (visited[i] || graph[start][i] == 0) continue;
        dfs(graph, visited, i, component);
    }
}

int main() {
    ifstream fin("graph.in");
    if (!fin.is_open()) {
        cerr << "Cannot open graph.in" << endl;
        return 1;
    }
    int n, k;
    fin >> n >> k;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    int from, to;
    for (int i = 0; i < k; i++) {
        fin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }
    fin.close();

    vector<bool> visited(n, false);
    size_t maxSize = 0;
    vector<size_t> maxComponent = {};
    for (size_t i = 0; i < n; i++) {
        if (visited[i]) continue;
        vector<size_t> component;
        dfs(graph, visited, i, component);
        if (maxSize < component.size()) {
            maxSize = component.size();
            maxComponent = component;
        }
    }

    ofstream fout("graph.out");
    if (!fout.is_open()) {
        cerr << "Cannot open graph.out" << endl;
        return 1;
    }
    for (size_t i = 0; i < maxComponent.size(); i++) {
        fout << maxComponent[i];
        if (i < maxComponent.size() - 1) fout << " ";
    }
    fout.close();

    return 0;
}