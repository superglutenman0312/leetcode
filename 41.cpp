#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> hash_tb;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] >= 1) hash_tb[nums[i]]++;
        }
        for (int i=1; i<=INT_MAX; i++) {
            if (hash_tb.find(i) == hash_tb.end()) return i;
        }
        return -1;
    }
};