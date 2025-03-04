#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    uint32_t gcd(uint32_t a, uint32_t b)
    {
        while (b != 0) {
            uint32_t next = b;
            b             = a % b;
            a             = next;
        }
        return a;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    uint32_t a = 35;
    uint32_t b = 49;
    cout << solution.gcd(a, b) << endl;

    return 0;
}