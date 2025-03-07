// binary_tree_util.h
#ifndef BINARY_TREE_UTIL_H
#define BINARY_TREE_UTIL_H

#include <iostream>
#include <queue>
#include <vector>

class BinaryTreeUtil
{
  public:
    struct TreeNode
    {
        int       val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr)
        {
        }
        TreeNode(int x) : val(x), left(nullptr), right(nullptr)
        {
        }
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
        {
        }
    };

    static TreeNode *findNode(TreeNode *root, int target)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == target)
            return root;
        TreeNode *left = findNode(root->left, target);
        if (left)
            return left;
        return findNode(root->right, target);
    }

    static TreeNode *buildTree(const std::vector<int> &nums)
    {
        if (nums.empty() || nums[0] == -1)
            return nullptr;

        TreeNode              *root = new TreeNode(nums[0]);
        std::queue<TreeNode *> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < nums.size()) {
            TreeNode *curr = q.front();
            q.pop();

            if (i < nums.size() && nums[i] != -1) {
                curr->left = new TreeNode(nums[i]);
                q.push(curr->left);
            }
            i++;

            if (i < nums.size() && nums[i] != -1) {
                curr->right = new TreeNode(nums[i]);
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }

    static void printTree(TreeNode *root)
    {
        if (!root) {
            std::cout << "Empty Tree" << std::endl;
            return;
        }

        printTreeHelper(root, 0, std::vector<bool>());
    }

    static void printTreeHelper(TreeNode *root, int depth, std::vector<bool> flag)
    {
        if (!root)
            return;

        // 打印前缀：表示层级关系
        for (int i = 0; i < depth; i++) {
            if (i == depth - 1) {
                std::cout << (flag[i] ? "├── " : "└── "); // 最后一层使用不同的符号
            } else {
                std::cout << (flag[i] ? "│   " : "    "); // 中间层使用竖线或空格
            }
        }
        std::cout << root->val << std::endl; // 打印当前节点值

        // 标记是否还有后续兄弟节点
        bool hasRight = root->right != nullptr;
        bool hasLeft  = root->left != nullptr;

        // 递归打印右子树
        if (hasRight) {
            flag.push_back(hasLeft); // 如果左子树存在，则标记为 true
            printTreeHelper(root->right, depth + 1, flag);
            flag.pop_back(); // 回溯
        }

        // 递归打印左子树
        if (hasLeft) {
            flag.push_back(false); // 左子树是最后一个分支，标记为 false
            printTreeHelper(root->left, depth + 1, flag);
            flag.pop_back(); // 回溯
        }
    }

    static void deleteTree(TreeNode *root)
    {
        if (!root)
            return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

#endif // BINARY_TREE_UTIL_H

using TreeNode = BinaryTreeUtil::TreeNode;