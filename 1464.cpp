#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num1 = nums[nums.size()-1], num2 = nums[nums.size()-2];
        return (num1-1) * (num2-1);
    }
};