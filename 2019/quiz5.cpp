#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

TreeNode* buildBST(TreeNode* node, int val) {
    if (node == nullptr) return new TreeNode(val);
    if (val < node->val) node->left = buildBST(node->left, val);
    if (val > node->val) node->right = buildBST(node->right, val);
    return node;
}

void getLeafPath(TreeNode* node, vector<vector<int>>& leafPaths, vector<int>& path) {
    if (node == nullptr) return;

    path.push_back(node->val);

    if (node->left == nullptr && node->right == nullptr) leafPaths.push_back(path);

    getLeafPath(node->left, leafPaths, path);
    getLeafPath(node->right, leafPaths, path);

    path.pop_back();
}

int leafPathAmount(const vector<int>& path1, const vector<int>& path2) {
    int i = 0, j = 0;
    while (path1[i] == path2[j] && i < path1.size() && j < path2.size()) {i++;j++;}
    int amount = path1[i-1];
    while (i < path1.size()) amount += path1[i++];
    while (j < path2.size()) amount += path2[j++];
    return amount;
}

int findMaxLeafPath(const vector<vector<int>>& leafPaths) {
    int size = leafPaths.size();
    int maxAmount = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            auto path1 = leafPaths[i];
            auto path2 = leafPaths[j];
            maxAmount = max(maxAmount, leafPathAmount(path1, path2));
        }
    }
    return maxAmount;
}

int main() {
    ifstream inputFile("tree.in");
    if (!inputFile.is_open()) {
        cerr << "Error" << endl;
        return 1;
    }
    vector<int> nums;
    int tmp;
    while (inputFile >> tmp) {
        nums.push_back(tmp);
    }

    TreeNode* root = nullptr;
    for (int i : nums) {
        root = buildBST(root, i);
    }

    vector<vector<int>> leafPaths;
    vector<int> path;
    getLeafPath(root, leafPaths, path);
    cout << findMaxLeafPath(leafPaths) << endl;

    return 0;
}