#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cmp {
    bool operator() (int a, int b) {
        return a > b;
    }
};

int solvedByMaxHeap(const vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, Cmp> q;
    for (int i : nums)
        q.push(i);

    while (k-- > 1)
        q.pop();

    return q.top();
}

int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot)
            high--;
        nums[low] = nums[high];
        while (low < high && nums[low] < pivot)
            low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

int solvedByQuickSelect(vector<int> &nums, int low, int high, int k)
{
    if (low == high)
        return nums[low];

    int pivot = partition(nums, low, high);
    if (pivot == k)
        return nums[k];
    else if (pivot > k) {
        return solvedByQuickSelect(nums, low, pivot - 1, k);
    } else {
        return solvedByQuickSelect(nums, pivot + 1, high, k);
    }
}

int main()
{
    ifstream inputFile("array.in");
    int      n, k;
    inputFile >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        inputFile >> nums[i];
    }

    // quick select solution(optimal)
    cout << solvedByQuickSelect(nums, 0, nums.size() - 1, k - 1) << endl;
    // cout << solvedByMaxHeap(nums, k) << endl;

    return 0;
}