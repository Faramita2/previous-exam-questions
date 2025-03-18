#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSequenceLength(const vector<unsigned int>& nums) {

    int size = nums.size();
    if (size <= 2) return size;
    
    vector<unordered_map<int, int>> dp(size);

    int longest = 2;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            int delta = nums[i] - nums[j];

            if (dp[j].count(delta)) {
                dp[i][delta] = dp[j][delta] + 1;
            } else {
                dp[i][delta] = 2;
            }

            longest = max(longest, dp[i][delta]);
        }
    }
    return longest;
}


int main() {
    ifstream inputFile("input3.txt");
    if (!inputFile.is_open()) {
        cerr << "ERROR" << endl;
        return 1;
    }
    unsigned int tmp;
    vector<unsigned int> nums;
    while (inputFile >> tmp) {
        nums.push_back(tmp);
    }

    int res = longestSequenceLength(nums);

    cout << res << endl;

    return 0;
}