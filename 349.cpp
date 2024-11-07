#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> hash_table;
        vector<int> ans;
        for (int i=0; i<nums1.size(); i++) {
            hash_table[nums1[i]] = true;
        }
        for (int i=0; i<nums2.size(); i++) {
            if (hash_table[nums2[i]] == true) {
                ans.push_back(nums2[i]);
                hash_table[nums2[i]] = false;
            }
        }
        return ans;
    }
};