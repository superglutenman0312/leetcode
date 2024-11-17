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
    int now_depth = 0, max_depth = 0;
    void dfs(TreeNode* root) {
        int origin_dpeth = now_depth;
        now_depth++;
        if (!root->left && !root->right) {
            max_depth = max(max_depth, now_depth);
        }
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        now_depth = origin_dpeth;
    }
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return max_depth;
    }
};