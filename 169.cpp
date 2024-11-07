#include<bits/stdc++.h>
using namespace std;

// hash
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        for (int i=0; i<nums.size(); i++) {
            hash_table[nums[i]]++;
        }
        pair<int,int> ans = {0,0};
        for (auto i : hash_table) {
            if (i.second > ans.second) {
                ans.second = i.second;
                ans.first = i.first;
            }
        }
        return ans.first;
    }
};