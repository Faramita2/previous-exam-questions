#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

unordered_map<char, int> inorderMap;

struct TreeNode {
    char val;
    shared_ptr<TreeNode> left, right;
    TreeNode(char val): val(val), left(nullptr), right(nullptr) {}
};

shared_ptr<TreeNode> buildTree(const vector<char>& inorder, int instart, int inend, const vector<char>& postorder, int poststart, int postend) {
    if (instart > inend || poststart > postend) return nullptr;
    auto root = make_shared<TreeNode>(postorder[postend]);
    int pos = inorderMap[root->val];
    int leftNodeCount = pos - instart;
    root->left = buildTree(inorder, instart, pos - 1, postorder, poststart, poststart + leftNodeCount - 1);
    root->right = buildTree(inorder, pos + 1, inend, postorder, poststart + leftNodeCount, postend - 1);
    return root;
}

void preorder(shared_ptr<TreeNode> root, bool& isFirst, ofstream& outputFile) {
    if (root == nullptr) return;
    if (!isFirst) outputFile << " ";
    isFirst = false;
    outputFile << root->val;
    preorder(root->left, isFirst, outputFile);
    preorder(root->right, isFirst, outputFile);
}

int main() {
    ifstream inputFile("4.in");
    if (!inputFile.is_open()) {
        cerr << "Cannot open 4.in" << endl;
        return 1;
    }
    int n;
    inputFile >> n;
    vector<char> inorder(n);
    for (int i = 0; i < n; i++) {
        inputFile >> inorder[i];
        inorderMap[inorder[i]] = i;
    }
    vector<char> postorder(n);
    for (int i = 0; i < n; i++) inputFile >> postorder[i];
    inputFile.close();
    
    auto root = buildTree(inorder, 0, n - 1, postorder, 0, n - 1);
    bool isFirst = true;
    ofstream outputFile("4.out");
    if (!outputFile.is_open()) {
        cerr << "Cannot open 4.out" << endl;
        return 1;
    }
    preorder(root, isFirst, outputFile);
    outputFile.close();

    return 0;
}