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
    vector<int> val;
    vector<int> prefix_sum;
    int flag = 0;
    void dfs (TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (!flag) val.push_back(root->val);
        else {
            for (int i=0; i<val.size(); i++) {
                if (root->val == val[i]) {
                    root->val = root->val + prefix_sum[i];
                    break;
                }
            }
        }
        dfs(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        sort(val.begin(), val.end(), greater<int>());
        prefix_sum.push_back(0);
        for (int i=1; i<val.size(); i++) {
            prefix_sum.push_back(prefix_sum[i-1] + val[i-1]);
        }
        flag = 1;
        dfs(root);
        return root;
    }
};