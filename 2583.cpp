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
    long long int depth = 0;
    void dfs(TreeNode *root, long long int level, vector<long long int>& ans) {
        depth = max(depth, level);
        if (root->left) dfs(root->left, level+1, ans);
        ans[level] += root->val;
        if (root->right) dfs(root->right, level+1, ans);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long int> ans(100005, 0);
        dfs(root, 0, ans);
        depth++;
        if (k > depth) return -1;
        sort(ans.begin(), ans.begin() + depth, greater<long long int>());
        return ans[k-1];
    }
};