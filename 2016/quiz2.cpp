#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iomanip>
using namespace std;

int main() {
    double x;
    unsigned n;
    cin >> x >> n;

    int y = static_cast<int>(x * 100 + 0.5);

    if (y < n) {
        cout << "ERROR" << endl;
        return 1;
    }

    srand(static_cast<unsigned>(time(0)));
    set<int> splits;
    splits.insert(0);
    splits.insert(y);

    while (splits.size() < n + 1) {
        int div = rand() % (y - 1) + 1;
        splits.insert(div);
    }

    cout << fixed << setprecision(2);
    auto prev = splits.begin();
    for (auto it = next(splits.begin()); it != splits.end(); it++) {
        cout << (double)(*it - *prev) / 100 << " ";
        prev = it;
    }
    cout << endl;

    return 0;
}