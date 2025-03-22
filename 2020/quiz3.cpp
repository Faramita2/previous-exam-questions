#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("number.in");
    vector<string> nums;
    int num;
    while (fin >> num) {
        nums.push_back(to_string(num));
    }
    fin.close();

    sort(nums.begin(), nums.end(), [](const auto& a, const auto& b) { return a + b > b + a; });
    string res;
    if (!nums.empty()) {
        for (size_t i = 0; i < nums.size(); i++) {
            res += nums[i];
        }
    } else {
        res = "0";
    }
    cout << res << endl;

    return 0;
}