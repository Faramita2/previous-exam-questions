#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int start, int end)
{
    int pivot = nums[start];
    int low = start, high = end;
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

void quickSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;
    int pos = partition(nums, start, end);
    quickSort(nums, start, pos - 1);
    quickSort(nums, pos + 1, end);
}

int main()
{
    ifstream inputFile("2.in");
    int      n;
    inputFile >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        inputFile >> nums[i];
    }

    for (int i : nums)
        cout << i << " ";
    cout << endl;

    bool isOdd = n % 2 == 1;
    quickSort(nums, 0, n - 1);

    if (isOdd) {
        cout << nums[n / 2] << endl;
    } else {
        cout << nums[n / 2 - 1] << " " << nums[n / 2] << endl;
    }

    return 0;
}