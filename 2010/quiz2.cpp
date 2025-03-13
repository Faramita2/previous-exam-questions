#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> matrixProduct(const vector<vector<int>> &m1,
                                  const vector<vector<int>> &m2)
{
    // m1: nxm, m2: sxt
    int n = m1.size(), m = m1[0].size(), s = m2.size(), t = m2[0].size();
    cout << "n: " << n << ", m: " << m << ", s: " << s << ", t: " << t << endl;
    if (m != s) {
        cerr << "error" << endl;
        return {};
    }
    cout << "res is " << n << " x " << t << " matrix." << endl;
    vector<vector<int>> res(n, vector<int>(t, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            for (int k = 0; k < m; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> m1 = {{1, 2, 3}, {2, 3, 4}};
    vector<vector<int>> m2 = {{1, 2}, {3, 4}, {5, 6}};

    auto res = matrixProduct(m1, m2);

    for (auto &row : res) {
        for (int i : row)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}