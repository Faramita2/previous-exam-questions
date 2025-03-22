#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr)
    {
    }
};

unordered_map<TreeNode *, pair<int, int>> nodeChildrenMap;
unordered_map<int, TreeNode *>            indexNodeMap;
ofstream                                  outputFile("4.out");
vector<int>                               indegrees;

TreeNode *buildTree()
{
    for (auto &p : nodeChildrenMap) {
        TreeNode *node = p.first;
        auto [l, r]    = p.second;
        indegrees[l]++;
        indegrees[r]++;
        node->left  = indexNodeMap[l];
        node->right = indexNodeMap[r];
    }

    for (int i = 1; i < indegrees.size(); i++) {
        if (indegrees[i] == 0)
            return indexNodeMap[i];
    }

    return nullptr;
}

void lrn(TreeNode *node, int &count)
{
    if (node == nullptr)
        return;
    lrn(node->left, count);
    lrn(node->right, count);
    outputFile << node->val;
    if (count > 1)
        outputFile << " ";
    count--;
}

int main()
{
    int      size;
    ifstream inputFile("4.txt");
    inputFile >> size;
    int n, l, r;
    for (int i = 0; i < size; i++) {
        inputFile >> n >> l >> r;
        TreeNode *node        = new TreeNode(n);
        indexNodeMap[n]       = node;
        nodeChildrenMap[node] = {l, r};
    }

    indegrees      = vector<int>(size + 1, 0);
    TreeNode *root = buildTree();
    lrn(root, size);

    return 0;
}