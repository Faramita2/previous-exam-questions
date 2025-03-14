#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 2; i < n + 1; i++) {
        res = (res + k) % i;
    }
    cout << res + 1 << endl;

    return 0;
}