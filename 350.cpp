#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> hash_table;
        for (int i=0; i<nums1.size(); i++) {
            hash_table[nums1[i]]++;
        }
        for (int i=0; i<nums2.size(); i++) {
            if (hash_table.find(nums2[i]) != hash_table.end() && hash_table[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                hash_table[nums2[i]]--;
            }
        }
        return ans;
    }
};