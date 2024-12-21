#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int len = nums.size(), idx1 = 0, idx2 = len/2;
        vector<int> ans(len);
        for (int i=0; i<len; i++) {
            if (!(i%2)) ans[i] = nums[idx1++];
            else ans[i] = nums[idx2++];
        }
        return ans;
    }
};