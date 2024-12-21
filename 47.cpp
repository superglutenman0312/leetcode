#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& nums, vector<bool> visit) {
        if (sub_ans.size() == nums.size()) {
            ans.push_back(sub_ans);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // 避免重複的條件
            if (visit[i]) continue; // 已經選過，跳過
            if (i > 0 && nums[i] == nums[i - 1] && visit[i - 1]) continue;
            visit[i] = true; // 標記為已使用
            sub_ans.push_back(nums[i]);
            dfs(nums, visit);
            sub_ans.pop_back(); // 回溯
            visit[i] = false; // 還原狀態
        }
    }
    vector<int> sub_ans;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visit(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, visit);
        return ans;
    }
};