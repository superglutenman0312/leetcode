#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left_product(len, 1);
        vector<int> right_product(len, 1);
        vector<int> ans(len, 1);
        left_product[0] = 1;
        for (int i=1; i<len; i++) {
            left_product[i] = left_product[i-1] * nums[i-1];
        }
        right_product[len-1] = 1;
        for (int i=len-2; i>=0; i--) {
            right_product[i] = right_product[i+1] * nums[i+1];
        }
        for (int i=0; i<len; i++) {
            ans[i] = left_product[i] * right_product[i];
        }
        return ans;
    }
};
