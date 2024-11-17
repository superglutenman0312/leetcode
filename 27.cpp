#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int current = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]!=val) nums[current++] = nums[i];
        }
        return current;
    }
};

// 3,3 val = 3
// 3,2,2,3 val = 3
// 2,2,2,3
// 0,1,2,2,3,0,4,2 val = 2
// 0,1,3,0,3,0,4,4 val = 2
