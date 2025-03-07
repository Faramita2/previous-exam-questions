#include "../BinaryTreeUtil/binary_tree_util.h"
#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  private:
    TreeNode *insertBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);
        if (val < root->val)
            root->left = insertBST(root->left, val);
        else
            root->right = insertBST(root->right, val);
        return root;
    }

    void findLeafPaths(TreeNode *node, vector<int> &path,
                       vector<vector<int>> &leafPaths)
    {
        if (!node)
            return;

        path.push_back(node->val);

        if (!node->left && !node->right)
            leafPaths.push_back(path);

        findLeafPaths(node->left, path, leafPaths);
        findLeafPaths(node->right, path, leafPaths);

        path.pop_back();
    }

    int calculatePathSum(const vector<int> &path1, const vector<int> &path2)
    {
        int i = 0;
        // 去除两条路径公共的前面部分
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
            i++;
        }
        // 最后的公共父节点的值
        int sum = path1[i - 1];
        for (int j = i; j < path1.size(); j++)
            sum += path1[j];
        for (int j = i; j < path2.size(); j++)
            sum += path2[j];

        return sum;
    }

  public:
    int maxLeafPath(const vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        TreeNode *root = nullptr;
        for (int i = 0; i < nums.size(); i++) {
            root = insertBST(root, nums[i]);
        }

        BinaryTreeUtil::printTree(root);

        vector<int>         path = {};
        vector<vector<int>> leafPaths;
        findLeafPaths(root, path, leafPaths);

        // print leaf path
        for (auto p : leafPaths) {
            for (auto n : p) {
                cout << n << " ";
            }
            cout << endl;
        }

        int maxSum = 0;
        for (auto i = 0; i < leafPaths.size(); i++) {
            for (auto j = i + 1; j < leafPaths.size(); j++) {
                int sum = calculatePathSum(leafPaths[i], leafPaths[j]);
                cout << "Distance between leaf " << i + 1 << " and leaf "
                     << j + 1 << " is " << sum << endl;
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

int main()
{
    Solution           solution;
    PerformanceMonitor monitor;

    ifstream inputFile("tree.in");
    if (!inputFile.is_open()) {
        cerr << "cannot open file tree.in" << endl;
    }

    vector<int> nums;

    int value;
    while (inputFile >> value) {
        nums.push_back(value);
    }
    inputFile.close();

    for (auto n : nums) {
        cout << n << " ";
    }
    cout << endl;

    auto maxSum = solution.maxLeafPath(nums);
    cout << "Max path sum: " << maxSum << endl;

    return 0;
}