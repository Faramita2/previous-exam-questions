#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    ifstream inputFile("graph.in");
    inputFile >> n;
    vector<vector<int>> graph(n + 1, vector<int>{});
    int from, to;
    while (inputFile >> from >> to) {
        if (from == 0 && to == 0) break;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    cout << 1;
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    queue<int> q;
    for (int neighbor : graph[1]) {
        q.push(neighbor);
    }
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (visited[cur]) continue;
        cout << " ";
        cout << cur;
        visited[cur] = true;
        for (int neighbor : graph[cur]) {
            if (visited[neighbor]) continue;
            q.push(neighbor);
        }
    }

    return 0;
}