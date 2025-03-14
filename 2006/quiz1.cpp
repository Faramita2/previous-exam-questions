#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> invertMatrix(const vector<vector<int>> &matrix)
{
    int                 m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> res(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};

    auto res = invertMatrix(matrix);

    for (auto &v : res) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}