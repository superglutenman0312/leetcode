#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash_table; // value, idx
        for (int i=0; i<nums.size(); i++) {
            if (hash_table.find(nums[i]) != hash_table.end() && i - hash_table[nums[i]] <= k) return true;
            hash_table[nums[i]] = i;
        }
        return false;
    }
};