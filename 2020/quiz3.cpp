#include <cassert>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solve(vector<string> &nums)
{
    sort(nums.begin(), nums.end(),
         [](auto &a, auto &b) { return stoi(a + b) > stoi(b + a); });

    return accumulate(nums.begin() + 1, nums.end(), nums.front(),
                      [](auto &l, auto &r) { return l + r; });
}

int main()
{
    ifstream       inputFile("number.in");
    vector<string> nums;
    unsigned int   tmp;
    while (inputFile >> tmp) {
        nums.push_back(to_string(tmp));
    }

    cout << solve(nums) << endl;

    return 0;
}