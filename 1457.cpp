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

// 我好討厭TLE
class Solution {
public:
    int ans = 0;
    bool is_palindromic(vector<int>& path) {
        vector<int> cnt(10, 0);
        for (int i=0; i<path.size(); i++) {
            cnt[path[i]]++;
        }
        int odd = 0;
        for (int i=0; i<cnt.size(); i++) {
            if (cnt[i] % 2) odd++;
        }
        if (odd <= 1) return true;
        return false;
    }
    void dfs(TreeNode *root, vector<int>& path) {
        path.push_back(root->val);
        if (!root->left && !root->right) { // this node is leaf
            if(is_palindromic(path)) ans++;
        }
        if (root->left) dfs(root->left, path);
        if (root->right) dfs(root->right, path);
        path.pop_back();
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return ans;
    }
};

// 神奇的xor
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode *root, vector<int>& path, int mask) {
        path.push_back(root->val);
        mask ^= (1 << root->val);
        if (!root->left && !root->right) { // this node is leaf
            if ((mask & (mask-1)) == 0) ans++;
        }
        if (root->left) dfs(root->left, path, mask);
        if (root->right) dfs(root->right, path, mask);
        path.pop_back();
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path;
        dfs(root, path, 0);
        return ans;
    }
};
