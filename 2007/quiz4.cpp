#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

ifstream                 inputFile("4.in");
ofstream                 outputFile("4.out");
int                      n;
vector<char>             inorder;
vector<char>             postorder;
unordered_map<char, int> inorderIndexMap;

struct TreeNode
{
    char      val;
    TreeNode *left, *right;
    TreeNode(char val) : val(val), left(nullptr), right(nullptr)
    {
    }
};

TreeNode *buildTree(int instart, int inend, int poststart, int postend)
{
    if (inend - instart == 0 || postend - poststart == 0)
        return nullptr;
    TreeNode *node = new TreeNode(postorder[postend - 1]);

    int pos           = inorderIndexMap[node->val];
    int leftNodeCount = pos - instart;
    node->left = buildTree(instart, pos, poststart, poststart + leftNodeCount);
    node->right =
        buildTree(pos + 1, inend, poststart + leftNodeCount, postend - 1);
    return node;
}

void nlr(TreeNode *node, bool &isFirst)
{
    if (node == nullptr)
        return;
    if (!isFirst) {
        outputFile << " ";
    } else
        isFirst = false;
    outputFile << node->val;
    nlr(node->left, isFirst);
    nlr(node->right, isFirst);
}

int main()
{
    inputFile >> n;
    char tmp;
    for (int i = 0; i < n; i++) {
        inputFile >> tmp;
        inorder.push_back(tmp);
        inorderIndexMap[tmp] = i;
    }

    for (int i = 0; i < n; i++) {
        inputFile >> tmp;
        postorder.push_back(tmp);
    }

    // for (char c : inorder)
    //     cout << c << " ";
    // cout << endl;

    // for (char c : postorder)
    //     cout << c << " ";
    // cout << endl;

    // for (auto &p : inorderIndexMap)
    //     cout << p.first << " : " << p.second << endl;

    TreeNode *root = buildTree(0, n, 0, n);

    bool isFirst = true;
    nlr(root, isFirst);

    return 0;
}