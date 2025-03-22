#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    double d = 1.0;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        d /= i;
        sum += d;
    }
    cout << fixed << setprecision(4) << sum;

    return 0;
}