#include <bitset>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    unsigned int num;
    cin >> num;
    bitset<16> bits(num);
    bitset<4>  result(0);
    for (int i = 0; i < 4; ++i) {
        bool xorResult = 0;
        for (int j = 0; j < 4; ++j) {
            xorResult ^= bits[i * 4 + j];
        }
        result[i] = xorResult;
    }
    cout << result.to_ulong() << endl;

    return 0;
}