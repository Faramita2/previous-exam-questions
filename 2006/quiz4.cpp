#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int m, n;

vector<int> nums;
vector<int> path;

void print(const vector<int> &path)
{
    bool isFirst = true;
    for (int i : path) {
        if (!isFirst)
            cout << " ";
        isFirst = false;
        cout << i;
    }
    cout << endl;
}

void backtracking(int startIndex)
{
    if (path.size() == m) {
        print(path);
        return;
    }

    for (int i = startIndex; i < n; i++) {
        path.push_back(nums[i]);
        backtracking(i + 1);
        path.pop_back();
    }
}

int main()
{
    cin >> m >> n;
    // 给定两个数m和n，实现如下功能：如m=3，n=4时，输出(生成所有从 1 到 n 中选出
    // m 个数的组合)

    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }

    backtracking(0);

    return 0;
}