#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 两有序数组中寻找中位数:假设有两个数组A和B，分别包含有m和n个整致，数组元素均按照递增顺序排列，
// 请设计有效的算法确定两个数组中所有元素的中位数
// (“有效”指让法的时间复杂度尽可能的低，“中位数”指集合中大小居中的那个数)，并给出相应的时间复杂度。
// 例如，算法输入数组A={1,2,3}，B={3,5}，则算法输出为3({1,2,3,3,5}的中位数);
// 若算法输入A={1,2,3}，B={2,4,5}，则算法输出为2和3({1,2,2,3,4,5}的中位数)。

void printMid(vector<int> &nums1, vector<int> &nums2)
{
    int         size1 = nums1.size(), size2 = nums2.size();
    int         size = size1 + size2;
    vector<int> res(size, 0);
    int         i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (nums1[i] < nums2[j]) {
            res[k++] = nums1[i++];
        } else {
            res[k++] = nums2[j++];
        }
    }
    while (i < size1)
        res[k++] = nums1[i++];
    while (j < size2)
        res[k++] = nums2[j++];

    if (size % 2 == 1)
        cout << res[size / 2] << endl;
    else
        cout << res[size / 2 - 1] << "," << res[size / 2] << endl;
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 5};
    printMid(nums1, nums2);

    vector<int> nums3 = {1, 2, 3};
    vector<int> nums4 = {2, 4, 5};
    printMid(nums3, nums4);

    return 0;
}