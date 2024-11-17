#include<bits/stdc++.h>
using namespace std;

// vector紀錄大法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (nums.size()==1 || k==0) return;
        int begin_idx = nums.size() - k;
        vector<int> v;
        for (int i=begin_idx; i<nums.size(); i++) {
            v.push_back(nums[i]);
        }
        for (int i=begin_idx-1; i>=0; i--) {
            nums[i+k] = nums[i];
        }
        for (int i=0; i<v.size(); i++) {
            nums[i] = v[i];
        }
        return;
    }
};

// 反轉大法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (nums.size()==1 || k==0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        return;
    }
};
// [1,2,3,4]
// k = 2
// [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// [7,6,5,4,3,2,1]
