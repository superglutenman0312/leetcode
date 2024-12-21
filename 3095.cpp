#include<bits/stdc++.h>
using namespace std;

// N^3
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0, cnt = INT_MAX, now = 0;
        for (left = 0; left<nums.size(); left++) {
            for (right = left; right<nums.size(); right++) {
                for (int i = left; i<=right; i++) {
                    now |= nums[i];
                }
                if (now >= k) cnt = min(right-left+1, cnt);
                now = 0;
            }
        }
        return cnt == INT_MAX ? -1 : cnt;
    }
};