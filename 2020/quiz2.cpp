#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<tuple<int32_t, vector<int32_t>, int32_t>>
readTestCases(const string &filename)
{
    vector<tuple<int32_t, vector<int32_t>, int32_t>> testCases;
    ifstream                                         inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return testCases;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream   iss(line);
        int32_t         n, k;
        vector<int32_t> nums;
        int32_t         expected;

        iss >> n >> k;

        int32_t tmp;
        while (iss >> tmp) {
            nums.push_back(tmp);
        }
        expected = nums.back();
        nums.pop_back();

        testCases.push_back({k, nums, expected});
    }

    inputFile.close();
    return testCases;
}

class Solution
{
  public:
    int32_t findKthLargeNumber(int32_t k, vector<int> &nums)
    {
        if (nums.empty() || k > nums.size() || k <= 0)
            return -1;
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }

  private:
    int32_t quickSelect(vector<int32_t> &nums, int32_t start, int32_t end,
                        int32_t k)
    {
        if (start >= end) {
            return nums[start];
        }

        int32_t pivotIndex = partition_(nums, start, end);

        if (pivotIndex == k) {
            return nums[pivotIndex];
        } else if (pivotIndex > k) {
            return quickSelect(nums, start, pivotIndex - 1, k);
        } else {
            return quickSelect(nums, pivotIndex + 1, end, k);
        }
    }

    int32_t partition_(vector<int32_t> &nums, int32_t start, int32_t end)
    {
        int32_t pivot = nums[start];
        int32_t low = start, high = end;
        while (low < high) {
            while (low < high && nums[high] < pivot)
                high--;
            while (low < high && nums[low] >= pivot)
                low++;
            if (low < high)
                swap(nums[low], nums[high]);
        }
        swap(nums[low], nums[start]);
        return low;
    }

    int32_t partition(vector<int32_t> &nums, int32_t start, int32_t end)
    {
        int32_t pivot = nums[end];
        int32_t i     = start - 1;
        for (auto j = start; j < end; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[end]);
        return i + 1;
    }
};

void batchRun()
{
    Solution           solution;
    PerformanceMonitor monitor;

    string filename  = "array.in";
    auto   testCases = readTestCases(filename);

    int         fails = 0;
    vector<int> failedCasesNum;
    for (int i = 0; i < testCases.size(); i++) {

        auto [k, nums, expected] = testCases[i];

        int32_t actual = solution.findKthLargeNumber(k, nums);

        if (actual == expected) {
            std::cout << "Test case " << i + 1
                      << " PASSED, expected = " << expected
                      << ", actual = " << actual << std::endl;
        } else {
            fails++;
            failedCasesNum.push_back(i + 1);
            std::cout << "Test case " << i + 1
                      << " FAILED, expected = " << expected
                      << ", actual = " << actual << std::endl;
        }
    }
    cout << "\nFAILS total: " << fails << ". Test case number are: ";
    for (auto f : failedCasesNum) {
        cout << f << " ";
    }
    cout << endl;
}

int main()
{

    Solution        solution;
    vector<int32_t> nums = {80, 70, 60, 50, 40, 30, 20, 10};
    int             k    = 4;
    cout << solution.findKthLargeNumber(k, nums) << endl;

    batchRun();

    return 0;
}