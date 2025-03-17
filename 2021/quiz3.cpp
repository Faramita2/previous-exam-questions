#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool backtracking(const vector<int> &nums)
{
    if (nums.size() == 1) {
        return nums.front() == 24;
    }

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            vector<int> tmp;

            // 构造剩余的数字列表
            for (int k = 0; k < nums.size(); k++) {
                if (k != i && k != j) {
                    tmp.push_back(nums.at(k));
                }
            }

            // 计算当前两个数字的两个运算结果
            vector<int> computed = {nums[i] + nums[j], nums[i] * nums[j]};

            for (int num : computed) {
                tmp.push_back(num);
                if (backtracking(tmp))
                    return true;
                tmp.pop_back();
            }
        }
    }

    return false;
}

int main()
{
    vector<int> cards(4, 0);
    for (int i = 0; i < 4; i++)
        cin >> cards[i];

    cout << (backtracking(cards) ? "YES" : "NO") << endl;

    return 0;
}