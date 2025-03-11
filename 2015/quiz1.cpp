#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void print(vector<char> &path, int &order)
{
    ostringstream oss;
    oss << "第" << ++order << "种组合: ";
    for (auto i = 0; i < path.size(); i++) {
        oss << path[i];
        if (i != path.size() - 1) {
            oss << ",";
        }
    }
    cout << oss.str() << endl;
}

void solve(string &s, vector<char> &path, int startIndex, int &order)
{
    if (path.size() == 5) {
        print(path, order);
        return;
    }

    for (int i = startIndex; i < s.length(); i++) {
        path.push_back(s[i]);
        solve(s, path, i + 1, order);
        path.pop_back();
    }
}

int main()
{
    string       s = "abcdefjhij";
    vector<char> path;
    int          order = 0;
    solve(s, path, 0, order);

    return 0;
}