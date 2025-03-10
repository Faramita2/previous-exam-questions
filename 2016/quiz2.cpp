#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define MIN_AMOUNT 0.01

double roundToRealMoney(double amount)
{
    double factor = pow(10.0, 2);

    return round(amount * factor) / factor;
}

double generateRandomAmount(double remainAmount, uint32_t remainCount)
{
    random_device rd;
    mt19937       gen(rd());

    double maxAmount =
        max(MIN_AMOUNT, remainAmount - MIN_AMOUNT * (remainCount - 1));

    uniform_real_distribution<> dist(MIN_AMOUNT, maxAmount);
    return roundToRealMoney(dist(gen));
}

int main()
{
    double   remainAmount;
    uint32_t count;

    cin >> remainAmount >> count;
    remainAmount = roundToRealMoney(remainAmount);
    while (roundToRealMoney(remainAmount / count) - MIN_AMOUNT < 0) {
        cout << "Cannot distribute money, input again please!" << endl;
        cin >> remainAmount >> count;
        remainAmount = roundToRealMoney(remainAmount);
    }

    for (int i = 0; i < count - 1; i++) {
        double cur = generateRandomAmount(remainAmount, count - i);
        cout << fixed << setprecision(2) << cur << " ";
        remainAmount -= cur;
    }
    cout << fixed << setprecision(2) << remainAmount << endl;

    return 0;
}