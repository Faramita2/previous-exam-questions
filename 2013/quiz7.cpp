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
    TreeNode *lchild, *rchild;
    double    val;
    TreeNode(float val) : lchild(nullptr), rchild(nullptr), val(val)
    {
    }
};

struct Cmp
{
    bool operator()(TreeNode *l, TreeNode *r)
    {
        // 从小到大
        return l->val > r->val;
    }
};

unordered_map<TreeNode *, int> idxMap;
vector<string>                 ans;
string                         tmp;

void preOrder(TreeNode *root)
{
    if (!root)
        return;
    if (!root->lchild && !root->rchild) {
        ans[idxMap[root]] = tmp;
        return;
    }

    tmp += "0";
    preOrder(root->lchild);
    tmp.pop_back();

    tmp += "1";
    preOrder(root->rchild);
    tmp.pop_back();
}

int main()
{
    ifstream                                            inputFile("7.in");
    ofstream                                            outputFile("7.out");
    double                                              d;
    priority_queue<TreeNode *, vector<TreeNode *>, Cmp> pq;
    int                                                 idx = 0;
    while (inputFile >> d) {
        TreeNode *node = new TreeNode(d);
        pq.push(node);
        idxMap[node] = idx++;
    }
    ans.resize(pq.size());
    while (pq.size() != 1) {
        TreeNode *t1 = pq.top();
        pq.pop();
        TreeNode *t2 = pq.top();
        pq.pop();
        TreeNode *t = new TreeNode(t1->val + t2->val);
        t->lchild   = t1;
        t->rchild   = t2;
        pq.push(t);
    }
    TreeNode *root = pq.top();
    preOrder(root);
    for (string &s : ans) {
        outputFile << s << endl;
    }

    return 0;
}