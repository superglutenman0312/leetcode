#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool issym(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p && q || p && !q) return false;
        if (p->val != q->val) return false;
        return issym(p->left, q->right) && issym(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right) return true;
        if (!root->left && root->right || root->left && !root->right) return false;
        return issym(root->left, root->right);
    }
};