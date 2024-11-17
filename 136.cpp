#include<bits/stdc++.h>
using namespace std;

// hash table
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        for (int i=0; i<nums.size(); i++) {
            hash_table[nums[i]]++;
        }
        for (auto i : hash_table) {
            if (i.second == 1) return i.first;
        }
        return -1;
    }
};

// XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};