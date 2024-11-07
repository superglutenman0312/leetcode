#include<bits/stdc++.h>
using namespace std;

// 爆搜
class Solution {
public:
    int cnt = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target, 0, 0);
        return cnt;
    }
    void dfs(vector<int>& nums, int target, int pos, int cur_sum){
        if(pos == nums.size()){
            if(cur_sum == target) cnt+=1;
            return;
        }
        dfs(nums, target, pos+1, cur_sum+nums[pos]);
        dfs(nums, target, pos+1, cur_sum-nums[pos]);
        return;
    }
};

// DP
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;
        // dp[i][j]：在使用前i個數字情況下，總和是j的方法數
        for (int i = 0; i < n; ++i) {
            for (auto &a : dp[i]) {
                int sum = a.first, cnt = a.second;
                dp[i + 1][sum + nums[i]] += cnt;
                dp[i + 1][sum - nums[i]] += cnt;
            }
        }
        return dp[n][S];
    }
};