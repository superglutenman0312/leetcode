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
    int ans = 0;
    bool is_left_child = false;
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root->left && !root->right) {
            if (is_left_child) ans += root->val;
            return ans;
        }
        is_left_child = true;
        if (root->left) sumOfLeftLeaves(root->left);
        is_left_child = false;
        if (root->right) sumOfLeftLeaves(root->right);
        return ans;
    }
};