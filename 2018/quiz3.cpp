#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int solve(vector<int> &values, int total, int startIndex)
{
    if (total < 0)
        return -1;
    if (total == 0)
        return 0;
    for (int i = startIndex; i >= 0; i--) {
        int tmp = solve(values, total - values[i], i);
        if (tmp == -1)
            continue;
        return tmp + 1;
    }
    return -1;
}

int main()
{
    ifstream inputFile("input3.txt");
    int      n, total;
    inputFile >> total >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
        inputFile >> values[i];
    sort(values.begin(), values.end());
    int ans = solve(values, total, values.size() - 1);
    cout << (ans == -1 ? 0 : ans) << endl;

    return 0;
}