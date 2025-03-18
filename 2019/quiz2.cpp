#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string canBeTwoPowerSum(int num)
{
    if (num <= 0)
        return "NO";

    int bit1 = -1, bit2 = -1;
    int bit = 0;

    while (num != 0) {
        if (num & 1) {
            if (bit1 == -1)
                bit1 = bit;
            else if (bit2 == -1)
                bit2 = bit;
            else
                return "NO";
        }
        num >>= 1;
        bit++;
    }

    if (bit2 == -1)
        return "NO";

    int power1 = 1 << bit1;
    int power2 = 1 << bit2;

    return to_string(power1 + power2) + " = 2^" + to_string(bit1) + " + 2^" +
           to_string(bit2);
}

int main()
{
    int n1 = 5;
    cout << "Can n = " << n1 << " be split by two power sum? => "
         << canBeTwoPowerSum(n1) << endl;

    int n2 = 10;
    cout << "Can n = " << n2 << " be split by two power sum? => "
         << canBeTwoPowerSum(n2) << endl;

    int n3 = 7;
    cout << "Can n = " << n3 << " be split by two power sum? => "
         << canBeTwoPowerSum(n3) << endl;

    int n4 = 8;
    cout << "Can n = " << n4 << " be split by two power sum? => "
         << canBeTwoPowerSum(n4) << endl;

    int n5 = -8;
    cout << "Can n = " << n5 << " be split by two power sum? => "
         << canBeTwoPowerSum(n5) << endl;

    return 0;
}