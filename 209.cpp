#include<bits/stdc++.h>
using namespace std;

// TLE 8-1
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, ans = INT_MAX;
        for (left = 0; left<nums.size(); left++) {
            for (right = 0; right<nums.size(); right++) {
                for (int i=left; i<=right; i++) {
                    sum += nums[i];
                }
                if (sum >= target) ans = min(ans, right-left+1);
                sum = 0;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// sliding window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, ans = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
/*
[2,3,1,2,4,3]
target = 7
[4,3]
*/