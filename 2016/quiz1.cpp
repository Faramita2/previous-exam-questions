#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string toHex(int n)
{
    if (n == 0)
        return "0";
    const string hexChars   = "0123456789ABCDEF";
    bool         isNegative = n < 0;
    n                       = n < 0 ? -n : n;
    string res;
    while (n > 0) {
        int remain = n % 16;
        res += hexChars[remain];
        n /= 16;
    }
    if (isNegative)
        res += "-";
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << toHex(n) << endl;

    return 0;
}