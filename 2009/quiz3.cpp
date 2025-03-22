#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(char val): val(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<char>& chars, int& idx) {
    if (chars[idx] == '0') return nullptr;
    TreeNode *node = new TreeNode(chars[idx]);
    node->left = buildTree(chars, ++idx);
    node->right = buildTree(chars, ++idx);
    return node;
}

int getDepth(TreeNode *node) {
    if (node == nullptr) return 0;
    return max(getDepth(node->left), getDepth(node->right)) + 1;
}

void lnr(TreeNode *node, int depth, int maxDepth, bool& isFirst) {
    if (node == nullptr) return;
    lnr(node->left, depth + 1, maxDepth, isFirst);
    if (depth <= maxDepth / 2) {
        if (!isFirst) cout << " ";
        isFirst = false;
        cout << node->val;
    }
    lnr(node->right, depth + 1, maxDepth, isFirst);
}

int main() {
    ifstream inputFile("tree.in");
    char c;
    vector<char> chars;
    while (inputFile >> c) {
        chars.push_back(c);
    }

    int idx = 0;
    TreeNode *root = buildTree(chars, idx);
    int depth = getDepth(root);
    bool isFirst = true;
    lnr(root, 1, depth, isFirst);

    return 0;
}