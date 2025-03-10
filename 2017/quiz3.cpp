#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int solve(vector<int> nums)
{
    int n = nums.size();

    if (n == 1 || n == 2)
        return n;

    int longest = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d    = nums[j] - nums[i];
            int cur  = 2;
            int last = j;
            for (int k = last + 1; k < n; k++) {
                if (nums[k] - nums[last] == d) {
                    cur++;
                    last = k;
                }
            }
            longest = max(longest, cur);
        }
    }

    return longest;
}

int main()
{
    ifstream    inputFile("input3.txt");
    int         tmp;
    vector<int> nums;
    while (inputFile >> tmp) {
        nums.push_back(tmp);
    }
    for (int i : nums)
        cout << i << " ";
    cout << endl;

    cout << "longest: " << solve(nums) << endl;

    return 0;
}