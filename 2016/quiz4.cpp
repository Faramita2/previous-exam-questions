#include "../PerformanceMonitor/performance_monitor.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 给定一个二叉树的前序遍历和后序遍历，给出一种可能的中序遍历结果。
// 输入从文件4.in中给定。其中第一行是二叉树结点的个数，第二行是二叉树的前序遍历序列，第三行是后序遍历序列。
// 二叉树种的结点名称以大写字母表示，最多26个结点。
// 将结果输出到文件4.out，输出一种可能的中序遍历结果。
// Input:
// 5
// A B D C E
// D B E C A
// Output:
// D B A E C

unordered_map<char, int> preMap;
unordered_map<char, int> postMap;
vector<char>             preorder;
vector<char>             postorder;

struct TreeNode
{
    char      val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr)
    {
    }
};

TreeNode *buildTree(int preStart, int preEnd, int postStart, int postEnd)
{
    if (preEnd - preStart == 0 || postEnd - postStart == 0)
        return nullptr;

    TreeNode *node;
    char      c = preorder[preStart];

    node = new TreeNode(c);
    if (preEnd - preStart == 1)
        return node;

    int postIndex     = postMap[c];
    int leftNodeCount = postIndex - postStart;

    node->left = buildTree(preStart + 1, preStart + leftNodeCount + 1,
                           postStart, postIndex);
    node->right =
        buildTree(preStart + leftNodeCount + 1, preEnd, postIndex + 1, postEnd);

    return node;
}

void lnr(TreeNode *node, ofstream &outFile, int &count)
{
    if (node == nullptr)
        return;
    lnr(node->left, outFile, count);
    outFile << node->val;
    cout << node->val;
    if (count > 1) {
        outFile << " ";
        cout << " ";
    }
    count--;
    lnr(node->right, outFile, count);
}

void solve()
{
    int      size = preorder.size();
    ofstream outFile("4.out");
    if (size == 1) {
        outFile << preorder.back() << endl;
        return;
    }

    auto root = buildTree(0, size, 0, size);

    cout << "Inorder: ";
    lnr(root, outFile, size);
    cout << endl;
}

int main()
{
    ifstream inputFile("4.in");
    int      n;
    inputFile >> n;
    char tmp;
    for (int i = 0; i < n; i++) {
        inputFile >> tmp;
        preorder.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        inputFile >> tmp;
        postorder.push_back(tmp);
    }

    cout << "Preorder: ";
    for (int i = 0; i < n; i++) {
        char c    = preorder[i];
        preMap[c] = i;
        cout << c << " ";
    }
    cout << endl;
    cout << "Postorder: ";
    for (int i = 0; i < n; i++) {
        char c     = postorder[i];
        postMap[c] = i;
        cout << c << " ";
    }
    cout << endl;

    solve();

    return 0;
}