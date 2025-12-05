#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            int start = max(0, i - nums[i]);
            for (int j = start; j<=i; j++) {
                ans += nums[j];
            }
        }
        return ans;
    }
};

// prefix sum
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans = 0;
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        for (int i=0; i<nums.size(); i++) {
            int start = max(0, i - nums[i]);
            if (start > 0) ans += prefix[i] - prefix[start-1];
            else ans += prefix[i];
        }
        return ans;
    }
};