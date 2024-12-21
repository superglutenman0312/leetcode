#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int ,int> hash_tb;
        for (int i=0; i<arr.size(); i++) {
            hash_tb[arr[i]]++;
        }
        int max = -1, max_idx;
        for (auto i : hash_tb) {
            if (i.first == i.second && i.first > max) max = i.first;
        }
        return max;
    }
};