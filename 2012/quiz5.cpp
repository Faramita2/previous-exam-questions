#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("read.in");
    ofstream outputFile("read.out");
    int      n, m, s, t;
    inputFile >> n >> m;
    vector<vector<int>> dists(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> next(n + 1, vector<int>(n + 1, 0));
    inputFile >> s >> t;
    for (int i = 0; i < m; i++) {
        int from, to, dist;
        inputFile >> from >> to >> dist;
        dists[from][to] = dist;
        next[from][to]  = to;
    }
    for (int k = 1; k < n + 1; k++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (i == k || j == k || dists[i][k] == -1 || dists[k][j] == -1)
                    continue;
                int dist = dists[i][k] + dists[k][j];
                if (dists[i][j] > dist) {
                    dists[i][j] = dist;
                    next[i][j]  = k;
                }
            }
        }
    }
    if (dists[s][t] == -1) {
        outputFile << "can't arrive";
    } else {
        outputFile << dists[s][t] << endl;
        while (s != t) {
            outputFile << s << " ";
            s = next[s][t];
        }
        outputFile << t;
    }

    return 0;
}