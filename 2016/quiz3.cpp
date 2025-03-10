#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define PRECISE 0.00000001

double func(double x)
{
    return 2 * pow(x, 11) - 3 * pow(x, 8) - 5 * pow(x, 3) - 1;
}

// 求多项式的根2x^11 - 3x^8 - 5x^3 - 1 = 0，根的精度为0.00000001
double solve(double (*func)(double), double l, double r)
{
    if (r - l < PRECISE)
        return l;
    double mid = (r + l) / 2;
    double tmp = func(mid);
    if (tmp > 0)
        return solve(func, l, mid);
    else if (tmp < 0)
        return solve(func, mid, r);
    else
        return mid;
}

int main()
{
    cout << solve(func, 1, 2) << endl;

    return 0;
}