#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

ifstream inputFile("4.txt");
ofstream outputFile("4.out");

struct TreeNode
{
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr)
    {
    }
};

void lrn(TreeNode *node)
{
    if (!node)
        return;
    lrn(node->left);
    lrn(node->right);
    static bool first = true;
    if (!first)
        outputFile << " ";
    outputFile << node->val;
    first = false;
}

int main()
{
    int size;
    inputFile >> size;

    vector<TreeNode *> nodes(size + 1, nullptr);
    vector<int>        indegrees(size + 1, 0);

    for (int i = 0; i < size; i++) {
        int n, l, r;
        inputFile >> n >> l >> r;

        if (!nodes[n])
            nodes[n] = new TreeNode(n);

        if (l != 0) {
            if (!nodes[l])
                nodes[l] = new TreeNode(l);
            nodes[n]->left = nodes[l];
            indegrees[l]++;
        }

        if (r != 0) {
            if (!nodes[r])
                nodes[r] = new TreeNode(r);
            nodes[n]->right = nodes[r];
            indegrees[r]++;
        }
    }

    TreeNode *root = nullptr;
    for (int i = 1; i <= size; ++i) {
        if (indegrees[i] == 0) {
            root = nodes[i];
            break;
        }
    }

    if (!root) {
        cerr << "error" << endl;
        return 1;
    }

    lrn(root);

    return 0;
}