#include <fstream>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ifstream fin("number.in");
    if (!fin.is_open()) {
        cerr << "Cannot open number.in" << endl;
        return 1;
    }
    vector<int> nums;
    int num;
    while (fin >> num) {
        nums.push_back(num);
    }
    fin.close();

    int maxSum = INT_MIN;
    int curSum = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        curSum = max(nums[i], nums[i] + curSum);
        maxSum = max(curSum, maxSum);
    }

    ofstream fout("number.out");
    if (!fout.is_open()) {
        cerr << "Cannot open number.out" << endl;
        return 1;
    }
    fout << maxSum;
    fout.close();

    return 0;
}