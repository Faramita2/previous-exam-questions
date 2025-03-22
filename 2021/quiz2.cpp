#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    int count = 0;
    long long c = a ^ b;
    for (int i = 0; i < 64; i++) {
        count += (c & 1);
        c >>= 1;
    }
    cout << count << endl;
    return 0;
}