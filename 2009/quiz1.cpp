#include <bitset>
#include <iostream>

using namespace std;

int main() {
    int16_t tmp;
    cin >> tmp;
    bitset<16> num(tmp);
    bitset<4> result(0);

    for (int i = 0; i < 4; i++) {
        int xorResult = 0;
        for (int j = 0; j < 4; j++) {
            xorResult ^= num[j];
        }
        result = xorResult;
    }

    cout << result.to_ulong() << endl;

    return 0;
}