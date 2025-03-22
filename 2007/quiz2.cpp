#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    vector<int> result;

    bool countFlag = true;

    while (!q.empty()) {
        int person = q.front();
        q.pop();

        if (countFlag) {
            result.push_back(person);
        } else {
            q.push(person);
        }
        countFlag = !countFlag;
    }

    bool isFirst = true;
    for (int i : result) {
        if (!isFirst) cout << " ";
        isFirst = false;
        cout << i;
    }

    return 0;
}