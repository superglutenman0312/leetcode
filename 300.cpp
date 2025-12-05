#include<bits/stdc++.h>
using namespace std;

// DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); //dp[i] means the LIS that ends in nums[i]
        int ans = 1;
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// NlogN
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > ans.back()) ans.push_back(nums[i]); // 比較大，放最後面
            else if (nums[i] < ans.back()) { // 比較小，更新內部值
                auto idx = lower_bound(ans.begin(), ans.end(), nums[i]);
                *idx = nums[i];
            }
        }
        return ans.size();
    }
};
// 2 4 6,  3
// 2 3 6,  3

// back-tracking (會TLE)
class Solution {
public:
    size_t lis = 0;
    vector<int> now;
    bool is_valid(vector<int>& now) {
        for (int i=0; i<now.size(); i++) {
            if (i == 0) continue;
            if (now[i] <= now[i-1]) return false;
        }
        return true;
    }
    void dfs(vector<int>& nums, int level) {
        if (level == nums.size()) {
            if (is_valid(now)) lis = max(lis, now.size());
            return;
        }
        now.push_back(nums[level]);
        dfs(nums, level+1);
        now.pop_back();
        dfs(nums, level+1);
    }
    int lengthOfLIS(vector<int>& nums) {
        dfs(nums, 0);
        return lis;
    }
};

// 如果要印出正確順序
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); //dp[i] means the LIS that ends in nums[i]
        vector<int> pre(nums.size(), -1);
        int ans = 1, end = 0;
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if (ans < dp[i]) {
                ans = dp[i];
                end = i;
            }
        }
        while (end != -1) {
            cout << nums[end] << " ";
            end = pre[end];
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > ans.back()) ans.push_back(nums[i]);
            else {
                auto idx = lower_bound(ans.begin(), ans.end(), nums[i]);
                *idx = nums[i];
            }
        }
        return ans.size();
    }
};


/*
[10,9,2,5,3,7,101,18]
4, [2,3,7,101]
*/