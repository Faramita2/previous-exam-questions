#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(char val): val(val), left(nullptr), right(nullptr) {}
};

void printOdd(queue<TreeNode*>& q, ofstream& outputFile) {
    int level = 1;
    while (!q.empty()) {
        int size = q.size();
        bool isFirst = true;
        if (level % 2 == 1) {
            outputFile << "第 " << level << " 层结点: ";
        }
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            if (level % 2 == 1) {
                if (!isFirst) outputFile << ",";
                isFirst = false;
                outputFile << node->val;
            } 
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        if (level % 2 == 1) outputFile << endl;
        level++;
    }
}

int main() {
    ifstream inputFile("input_3.txt");
    ofstream outputFile("output_3.txt");
    
    map<char, int> indegrees;
    unordered_map<char, TreeNode*> nodeMap;
    string line;
    char a, b, c;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        iss >> a >> b;
        if (!nodeMap[a]) {
            nodeMap[a] = new TreeNode(a);
            indegrees[a] = 0;
        }
        if (!nodeMap[b]) {
            nodeMap[b] = new TreeNode(b);
        }


        nodeMap[a]->left = nodeMap[b];
        indegrees[b]++;
        
        if (iss >> c) {
            if (!nodeMap[c])
                nodeMap[c] = new TreeNode(c);
            nodeMap[a]->right = nodeMap[c];
            indegrees[c]++;
        }
    }

    auto p = *indegrees.begin();
    TreeNode *root = nodeMap[p.first];

    queue<TreeNode*> q;
    q.push(root);
    printOdd(q, outputFile);

    return 0;
}