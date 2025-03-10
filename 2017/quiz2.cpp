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

bool isOk(int num)
{
    int sum = 1, tmp = num, i = 2;
    while (i <= sqrt(tmp)) {
        if (tmp % i != 0) {
            i++;
            continue;
        }
        tmp /= i;
        sum += i;
        i = 2;
    }
    if (tmp != num) {
        sum += tmp;
    }
    return sum >= num;
}

int main()
{
    int flag = 0;
    for (int i = 2; i <= 1000; i++) {
        if (isOk(i)) {
            if (flag)
                cout << " ";
            cout << i;
            flag = 1;
        }
    }
    cout << endl;
    return 0;
}