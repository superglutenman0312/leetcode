#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            int left = -1, right = -1;
            if (i - k >= 0) left = nums[i-k];
            if (i + k <= nums.size()-1) right = nums[i+k];
            if (nums[i] > left && nums[i] > right) sum += nums[i];
        }
        return sum;
    }
};