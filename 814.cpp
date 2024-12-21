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
    bool dfs(TreeNode *root) {
        bool is_delete = true;
        if (root->val) is_delete = false;
        if (root->left) {
            bool is_left_node_del = dfs(root->left);
            if (is_left_node_del) {
                TreeNode *del = root->left;
                root->left = nullptr;
                delete(del);
            }
            is_delete = min(is_delete, is_left_node_del);
        }
        if (root->right) {
            bool is_right_node_del = dfs(root->right);
            if (is_right_node_del) {
                TreeNode *del = root->right;
                root->right = nullptr;
                delete(del);
            }
            is_delete = min(is_delete, is_right_node_del);
        }
        return is_delete;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root) == false ? root : nullptr;
    }
};