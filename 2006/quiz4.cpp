#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& path) {
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << " ";
    }
    cout << endl;
}

void backtracking(vector<int>& path, int m, int n, int start) {
    if (path.size() == m) {
        print(path);
        return;
    }

    for (int i = start; i <= n; i++) {
        path.push_back(i);
        backtracking(path, m, n, i + 1);
        path.pop_back();
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> path;
    backtracking(path, m, n, 1);

    return 0;
}