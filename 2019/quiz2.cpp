#include <bitset>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bitset<32> bits(n);
    if (bits.count() != 2) {
        cout << "NO" << endl;
    } else {
        int a[2], idx = 0;
        for (size_t i = 0; i < 32; i++) {
            if (bits[i]) {
                a[idx++] = i;
            }
        }
        printf("%d = 2^%d + 2^%d\n", n, a[1], a[0]);
    }

    return 0;
}