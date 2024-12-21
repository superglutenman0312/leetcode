#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int cnt = 0, sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if (!sum) cnt++;
        }
        return cnt;
    }
};