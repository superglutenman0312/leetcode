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
    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (depth % 2 == 0) {
            TreeNode *ll = nullptr, *lr = nullptr, *rl = nullptr, *rr = nullptr;
            if (root->left) {
                ll = root->left->left;
                lr = root->left->right;
            }
            if (root->right) {
                rl = root->right->left;
                rr = root->right->right;
            }
            if (root->left) {
                root->left->left = rl;
                root->left->right = rr;
            }
            if (root->right) {
                root->right->left = ll;
                root->right->right = lr;
            }
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};

class Solution {
public:
    void dfs(TreeNode *left, TreeNode *right, int depth) {        
        if (depth % 2) {
            swap(left->val, right->val);
        }
        if (left->left) dfs(left->left, left->right, depth+1);
        if (right->right) dfs(right->left, right->right, depth+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }
};