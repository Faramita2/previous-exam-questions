#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("input_4.txt");
    if (!inputFile.is_open()) {
        cerr << "Error, input_4.txt is not opened." << endl;
        return 1;
    }
    ofstream outputFile("output_4.txt");
    if (!outputFile.is_open()) {
        cerr << "Error, output_4.txt is not opened." << endl;
        return 1;
    }

    int n, k;
    inputFile.ignore(2);
    inputFile >> n;
    inputFile.ignore(3);
    inputFile >> k;
    inputFile.ignore(1);
    cout << "n: " << n << ", k: " << k << endl;
    cout << endl;

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        matrix[i][i] = 0;
        path[i][i]   = i;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int           vFrom;
        iss >> vFrom;
        cout << "vFrom: " << vFrom << endl;
        int vTo, dist;
        while (iss >> vTo >> dist) {
            cout << "vTo: " << vTo << endl;
            cout << "dist: " << dist << endl;
            matrix[vFrom][vTo] = dist;
            path[vFrom][vTo]   = vTo;
        }
        cout << endl;
    }
    cout << endl;

    for (auto &v : matrix) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (auto &v : path) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    for (int x = 0; x < n; x++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][x] == INT_MAX || matrix[x][j] == INT_MAX)
                    continue;
                int sum = matrix[i][x] + matrix[x][j];

                if (sum < matrix[i][j]) {
                    matrix[i][j] = sum;
                    path[i][j]   = x;
                }
            }
        }
    }

    int cur = 1;
    outputFile << cur;
    while (cur != k) {
        cur = path[cur][k];
        outputFile << " " << cur;
    }

    while (cur != n) {
        cur = path[cur][n];
        outputFile << " " << cur;
    }

    return 0;
}