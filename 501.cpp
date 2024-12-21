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
    void dfs (TreeNode *root) {
        if (root->left) dfs(root->left);
        hash_tb[root->val] += 1;
        if (root->right) dfs(root->right);
    }
    vector<int> ans;
    unordered_map<int,int> hash_tb;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int max_cnt = 0;
        for (auto i : hash_tb) {
            max_cnt = max(max_cnt, i.second);
        }
        for (auto i : hash_tb) {
            if (i.second == max_cnt) ans.push_back(i.first);
        }
        return ans;
    }
};