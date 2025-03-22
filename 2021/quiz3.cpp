#include <iostream>
#include <vector>

using namespace std;

bool backtracking(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums.front() == 24;
    }

    for (size_t i = 0; i < nums.size() - 1; i++) {
        for (size_t j = i + 1; j < nums.size(); j++) {
            vector<int> tmp;
            for (size_t k = 0; k < nums.size(); k++) {
                if (k != i && k != j) {
                    tmp.push_back(nums[k]);
                }
            }
            tmp.push_back(nums[i] + nums[j]);
            if (backtracking(tmp)) return true;
            tmp.pop_back();

            tmp.push_back(nums[i] * nums[j]);
            if (backtracking(tmp)) return true;
            tmp.pop_back();
        }
    }

    return false;
}

int main() {
    vector<int> nums(4);
    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
    }
    
    bool res = backtracking(nums);

    cout << (res ? "YES" : "NO") << endl;

    return 0;
}