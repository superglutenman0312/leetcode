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
    int countNodes(TreeNode* root) {
        int left_depth = 1, right_depth = 1, ans = 0;
        TreeNode *now = root;
        // check left leaf
        while (now->left) {
            left_depth++;
            now = now->left;
        }
        // check right leaf
        now = root;
        while (now->right) {
            right_depth++;
            now = now->right;
        }
        if (left_depth == right_depth) return pow(2,left_depth) - 1;
        else return countNodes(root->left) + countNodes(root->right);
    }
};