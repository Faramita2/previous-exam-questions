#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<char> preorder, postorder;
unordered_map<char, int> preorderIndexMap;
unordered_map<char, int> postorderIndexMap;

struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(char val): val(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(int prestart, int preend, int poststart, int postend) {
    if (prestart > preend || poststart > postend) return nullptr;

    TreeNode* root = new TreeNode(postorder[postend]);

    if (poststart == postend) return root;

    char leftRoot = preorder[prestart + 1];
    int leftRootIndex = postorderIndexMap[leftRoot];

    int leftNodeCount = leftRootIndex - poststart + 1;

    root->left = buildTree(prestart + 1, prestart + leftNodeCount, poststart, leftRootIndex);
    root->right = buildTree(prestart + leftNodeCount + 1, preend, leftRootIndex + 1, preend - 1);

    return root;
}

void lnr(TreeNode* node, ofstream& outputFile, bool& isFirst) {
    if (node == nullptr) return;
    if (node->left != nullptr) lnr(node->left, outputFile, isFirst);
    if (!isFirst) {
        outputFile << " ";
    }
    isFirst = false;
    outputFile << node->val;
    if (node->right != nullptr) lnr(node->right, outputFile, isFirst);
}

int main() {
    ifstream inputFile("4.in");
    int n;
    inputFile >> n;
    preorder = vector<char>(n, ' ');
    for (int i = 0; i < n; i++) {
        inputFile >> preorder[i];
        preorderIndexMap[preorder[i]] = i;
    }
    postorder = vector<char>(n, ' ');
    for (int i = 0; i < n; i++) {
        inputFile >> postorder[i];
        postorderIndexMap[postorder[i]] = i;
    }

    TreeNode* root = buildTree(0, n - 1, 0, n - 1);
    ofstream outputFile("4.out");
    bool isFirst = true;
    lnr(root, outputFile, isFirst);

    return 0;
}