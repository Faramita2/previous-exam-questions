#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

ifstream inputFile("tree.in");

struct TreeNode
{
    char      val;
    TreeNode *left, *right;
    TreeNode(char val) : val(val), left(nullptr), right(nullptr)
    {
    }
};

int height = 0;

TreeNode *buildTree(const string &s, int &index)
{
    if (index >= s.size() || s[index] == '0') {
        index++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(s[index++]);

    node->left  = buildTree(s, index);
    node->right = buildTree(s, index);

    return node;
}

int getHeight(TreeNode *node)
{
    if (node == nullptr)
        return -1;
    int lHeight = getHeight(node->left);
    int rHeight = getHeight(node->right);
    return max(lHeight, rHeight) + 1;
}

void lnr(TreeNode *node, int curHeight, bool &isFirst)
{
    if (node == nullptr)
        return;
    lnr(node->left, curHeight + 1, isFirst);
    if (curHeight <= height / 2) {
        if (!isFirst)
            cout << " ";
        cout << node->val;
        isFirst = false;
    }
    lnr(node->right, curHeight + 1, isFirst);
}

int main()
{
    string chars;
    inputFile >> chars;
    cout << chars << endl;

    int       index = 0;
    TreeNode *root  = buildTree(chars, index);

    height = getHeight(root);
    cout << "height: " << height << endl;
    bool isFirst = true;
    lnr(root, 0, isFirst);

    return 0;
}