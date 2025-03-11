#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode
{
    char      val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(char x, TreeNode *left) : val(x), left(left), right(nullptr) {};
    TreeNode(char x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {};
};

TreeNode *buildTree(char c, unordered_map<char, vector<char>> &nodeChildren,
                    unordered_map<char, TreeNode *> &nodeMap)
{
    TreeNode *node;
    if (!nodeMap.count(c)) {
        node       = new TreeNode(c);
        nodeMap[c] = node;
    } else
        node = nodeMap[c];

    if (!nodeChildren.count(c))
        return node;
    else {
        auto children = nodeChildren[c];
        node->left    = buildTree(children[0], nodeChildren, nodeMap);
        node->right   = children.size() == 1
                            ? nullptr
                            : buildTree(children[1], nodeChildren, nodeMap);
    }

    return node;
}

void output(TreeNode *root, ofstream &outputFile)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
        int  size    = q.size();
        bool isFirst = true;

        for (int i = 0; i < size; i++) {
            auto node = q.front();
            q.pop();

            if (level % 2 == 1) {
                if (isFirst) {
                    isFirst = false;
                    outputFile << "第" << " " << level << " 层结点: ";
                }
                outputFile << node->val;
                if (i != size - 1)
                    outputFile << ",";
            }

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        if (level % 2 == 1)
            outputFile << endl;
        level++;
    }
}

int main()
{
    unordered_map<char, vector<char>> nodeChildren;
    unordered_map<char, TreeNode *>   nodeMap;
    ifstream                          inputFile("input_3.txt");
    ofstream                          outputFile("output_3.txt");
    string                            line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        char          node, left, right;
        iss >> node >> left;
        vector<char> children = {left};
        if (iss >> right) {
            children.push_back(right);
        }
        nodeChildren[node] = children;
    }
    inputFile.close();
    auto root = buildTree('A', nodeChildren, nodeMap);

    output(root, outputFile);
    outputFile.close();

    return 0;
}