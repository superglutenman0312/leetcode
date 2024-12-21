#include<bits/stdc++.h>
using namespace std;

// hash
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_tb;
        for (int i=0; i<nums.size(); i++) {
            hash_tb[nums[i]]++;
        }
        int max_val = 0, max_cnt = 0;
        vector<int> ans;
        while (k--) {
            for (auto i : hash_tb) {
                if (i.second > max_cnt) {
                    max_cnt = i.second;
                    max_val = i.first;
                }
            }
            hash_tb[max_val] = 0;
            ans.push_back(max_val);
            max_cnt = 0;
            max_val = 0;
        }
        return ans;
    }
};

// min_heap
