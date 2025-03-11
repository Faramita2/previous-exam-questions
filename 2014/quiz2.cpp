#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool isNegative = false;
    if (n < 0) {
        isNegative = true;
        n          = -n;
    }
    string s;
    while (n > 0) {
        s += to_string(n % 8);
        n /= 8;
    }
    if (isNegative)
        s += "-";
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}