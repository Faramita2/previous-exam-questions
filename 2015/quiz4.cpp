#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("input_4.txt");
    ofstream outputFile("output_4.txt");
    int n, k;
    inputFile.ignore(2);
    inputFile >> n;
    inputFile.ignore(3);
    inputFile >> k;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i < n + 1; i++) {
        next[i][i] = i;
    }
    int from, to, dist;
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        iss >> from;
        while (iss >> to >> dist) {
            graph[from][to] = dist;
            next[from][to] = to;
        }
    }

    for (int x = 1; x < n + 1; x++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (graph[i][x] == INT_MAX || graph[x][j] == INT_MAX) continue;
                int dist = graph[i][x] + graph[x][j];
                if (graph[i][j] > dist)
                {
                    next[i][j] = x;
                    graph[i][j] = dist;
                }
            }
        }
    }

    int cur = 1;
    outputFile << cur;
    while (cur != k) {
        cur = next[cur][k];
        outputFile << " " << cur;
    }
    while (cur != n) {
        cur = next[cur][n];
        outputFile << " " << cur;
    }

    return 0;
}