#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        for (int i=0; i<nums.size(); i++) {
            hash_table[nums[i]]++;
        }
        for (auto i : hash_table) {
            if (i.second > 1) return true;
        }
        return false;
    }
};