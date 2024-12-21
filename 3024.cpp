#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_map<int, int> hash_tb;
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) return "none";
        for (int i=0; i<nums.size(); i++) {
            hash_tb[nums[i]]++;
        }
        int maxx = 0;
        for (auto i : hash_tb) {
            maxx = max(maxx, i.second);
        }
        if (maxx == 3) return "equilateral";
        if (maxx == 2) return "isosceles";
        return "scalene";
    }
};