#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int unique_num_idx = 0, current = 1;
        for(int i=0; i<nums.size(); i++){
            if (nums[i]!=nums[unique_num_idx]) {
                unique_num_idx = i;
                nums[current++] = nums[i];
            }
        }
        return current;
    }
};

// 1 1 2
// 1 2 2
// 0,0,1,1,1,2,2,3,3,4
// 0,1,1,1,1,2,2,3,3,4