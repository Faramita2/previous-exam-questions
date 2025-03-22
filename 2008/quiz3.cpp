#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> invertMatrix(vector<vector<int>> &matrix)
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
    vector<vector<int>> m = {{1, 2}, {4, 5}, {7, 8}};
    for (auto &row : m) {
        for (int i : row) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    auto res = invertMatrix(m);

    for (auto &row : res) {
        for (int i : row) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}