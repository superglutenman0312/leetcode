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
    int now_sum = 0;
    bool flag = false;
    void dfs (TreeNode* root, int targetSum) {
        int origin_sum = now_sum;
        now_sum += root->val;
        if (!root->left && !root->right) {
            if (now_sum == targetSum) flag = true;
        }
        if (root->left) dfs(root->left, targetSum);
        if (root->right) dfs(root->right, targetSum);
        now_sum = origin_sum;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        dfs(root, targetSum);
        return flag;
    }
};