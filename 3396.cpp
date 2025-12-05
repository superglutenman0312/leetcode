#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_valid(unordered_map<int, int>& hash_tb) {
        for (auto i : hash_tb) {
            if (i.second > 1) return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> hash_tb;
        int ans = 0, idx = 0;
        for (int i=0; i<nums.size(); i++) {
            hash_tb[nums[i]]++;
        }
        while (is_valid(hash_tb) == false) {
            for (int i=0; i<3; i++) {
                if (idx+i < nums.size()) hash_tb[nums[idx+i]]--;
            }
            idx += 3;
            ans++;
        }
        return ans;
    }
};