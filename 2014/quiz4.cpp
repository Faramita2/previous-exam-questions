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
        cerr << "Error, cannot open graph.in." << endl;
        return 1;
    }
    int n;
    inputFile >> n;
    inputFile.ignore();
    int                 from, to;
    string              line;
    vector<vector<int>> graph(n + 1);
    while (getline(inputFile, line)) {
        istringstream iss(line);
        iss >> from >> to;
        if (from == 0 && to == 0)
            break;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<bool> visited(n + 1, false);
    queue<int>   next;
    next.push(1);
    visited[1] = true;

    vector<int> vertexes;
    while (!next.empty()) {
        int cur = next.front();
        next.pop();

        vertexes.push_back(cur);

        for (int neighbor : graph[cur]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                next.push(neighbor);
            }
        }
    }

    ostringstream output;
    for (int v : vertexes) {
        output << v;
        if (n-- > 1)
            output << " ";
    }

    cout << output.str() << endl;

    return 0;
}