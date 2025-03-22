#include <iostream>

using namespace std;

int main() {
    long long a, b;

    cin >> a >> b;
    long long tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    cout << a << endl;

    return 0;
}