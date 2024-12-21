#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& nums, int level) {
        if (sub_ans.size() == nums.size()) {
            ans.push_back(sub_ans);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (!visit[i]) {
                sub_ans.push_back(nums[i]);
                visit[i] = true;
                dfs(nums, level + 1);
                sub_ans.pop_back();
                visit[i] = false;
            }
        }
    }
    vector<int> sub_ans;
    vector<vector<int>> ans;
    bool visit[7] = {false};
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};