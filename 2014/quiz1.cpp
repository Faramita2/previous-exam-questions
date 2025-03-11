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
    string s;
    getline(cin, s);
    cout << s << endl;
    int alpha = 0, numeric = 0, space = 0, other = 0;
    for (char c : s) {
        if (isalpha(c))
            alpha++;
        else if (isdigit(c))
            numeric++;
        else if (isspace(c))
            space++;
        else
            other++;
    }
    cout << "alpha: " << alpha << ", numeric: " << numeric
         << ", space: " << space << ", other: " << other << endl;

    return 0;
}