#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

struct TreeNode
{
    TreeNode *left{nullptr};
    TreeNode *right{nullptr};
    int       val;
    TreeNode(int val) : val{val}
    {
    }
};

TreeNode *root = nullptr;

void insertNode(int val)
{
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    TreeNode *cur  = root;
    TreeNode *prev = nullptr;
    while (cur) {
        prev = cur;
        if (val < cur->val) {
            cur = cur->left;
        } else if (val > cur->val) {
            cur = cur->right;
        } else {
            assert(false);
        }
    }
    assert(prev);
    if (val < prev->val) {
        prev->left = new TreeNode(val);
    } else {
        prev->right = new TreeNode(val);
    }
}

#define MAX(a, b, c) max(a, max(b, c))

// 求从根节点到叶结点的最短路径
int getMaxPath(TreeNode *root)
{
    if (!root) {
        return 0;
    }
    int ans = root->val + max(getMaxPath(root->left), getMaxPath(root->right));
    return ans;
}

// 求以root为根节点的树中，两个叶结点之间的最长路径，有三种可能性：
// 1. 最长路径经过该根节点
// 2. 最长路径在左子树
// 3. 最长路径在右子树
int getMaxDist(TreeNode *root)
{
    if (!root) {
        return 0;
    }
    return MAX(getMaxDist(root->left), getMaxDist(root->right),
               root->val + getMaxPath(root->left) + getMaxPath(root->right));
}

int main()
{
    ifstream ifs("tree.in");
    int      val;
    while (ifs >> val) {
        insertNode(val);
    }
    cout << getMaxDist(root) << endl;
    return 0;
}
