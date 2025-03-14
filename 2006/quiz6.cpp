#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream    inputFile("number.in");
    ofstream    outputFile("number.out");
    int         n;
    vector<int> nums;
    while (inputFile >> n) {
        nums.push_back(n);
    }
    int res = INT_MIN;
    int cur = 0;
    for (int i : nums) {
        if (cur <= 0) {
            cur = max(i, cur);
        } else {
            cur += i;
            res = max(cur, res);
        }
    }
    outputFile << res;

    return 0;
}