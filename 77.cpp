#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int val = 1;
    void dfs(int n, int k, int level) {
        if (sub_ans.size() == k) {
            ans.push_back(sub_ans);
            return;
        }
        for (int i=level; i<=n; i++) {
            sub_ans.push_back(i);
            dfs(n, k, i + 1);
            sub_ans.pop_back();
        }
    }
    vector<vector<int>> ans;
    vector<int> sub_ans;
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};


// 1 2 3 4
// {1 2} {1 3} {1 4}...