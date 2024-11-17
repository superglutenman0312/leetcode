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
    string path;
    vector<string> ans;
    void node_check(TreeNode* root) {
        string original_path = path;
        if (path.empty()) path.append(to_string(root->val));
        else {
            path.append("->");
            path.append(to_string(root->val));
        }
        if (!root->left && !root->right) ans.push_back(path);
        if (root->left) node_check(root->left);
        if (root->right) node_check(root->right);
        path = original_path;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        node_check(root);
        return ans;        
    }
};
/*
          1
        2   3
       5 6

*/