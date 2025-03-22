#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int partition(vector<int>& nums, int start, int end) {
    int low = start, high = end;
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot) high--;
        nums[low] = nums[high];
        while (low < high && nums[low] < pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

void quickSort(vector<int>& nums, int start, int end) {
    if (start < end) {
        int pos = partition(nums, start, end);
        quickSort(nums, start, pos - 1);
        quickSort(nums, pos + 1, end);
    }
}

int main() {
    string tmp;
    vector<int> nums;
    int num;
    getline(cin, tmp);
    istringstream iss(tmp);
    while (iss >> num) {
        nums.push_back(num);
    }

    quickSort(nums, 0, nums.size() - 1);

    int n = nums.size();
    if (n % 2 == 1) {
        cout << nums[n / 2 - 1] << endl;
    } else {
        cout << nums[n / 2 - 1] << " " << nums[n / 2] << endl;
    }

    return 0;
}