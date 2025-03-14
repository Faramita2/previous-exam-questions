#include <cassert>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    int cnt = 1, flag = 0;
    while (!q.empty()) {
        if (cnt == 1) {
            if (flag)
                cout << " ";
            flag = 1;
            cout << q.front();
            q.pop();
            cnt = 2;
        } else {
            q.push(q.front());
            q.pop();
            cnt = 1;
        }
    }

    return 0;
}