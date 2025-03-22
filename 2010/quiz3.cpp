#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int       val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr)
    {
    }
};

TreeNode *buildBST(TreeNode *&root, int val)
{
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (root->val > val)
        root->left = buildBST(root->left, val);

    if (root->val < val)
        root->right = buildBST(root->right, val);

    return root;
}

void lrn(TreeNode *node, bool &isFirst)
{
    if (node == nullptr)
        return;
    lrn(node->left, isFirst);
    lrn(node->right, isFirst);
    if (!isFirst)
        cout << " ";
    cout << node->val;
    isFirst = false;
}

int main()
{
    int       val;
    TreeNode *root = nullptr;
    while (cin >> val) {
        if (val == 0)
            break;
        root = buildBST(root, val);
    }
    bool isFirst = true;
    lrn(root, isFirst);

    return 0;
}