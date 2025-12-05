#include<bits/stdc++.h>
using namespace std;

// N2 (TLE)
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0, target = INT_MAX, target_idx = 0;
        vector<bool> mark(nums.size(), false);
        bool flag = false;
        while (1) {
            for (int i=0; i<nums.size(); i++) {
                if (!mark[i]) {
                    target = nums[i];
                    target_idx = i;
                    break;
                }
                if (i == nums.size()-1) flag = true;
            }
            if (flag) break;
            for (int i=0; i<nums.size(); i++) {
                if (!mark[i] && nums[i] < target) {
                    target = nums[i];
                    target_idx = i;
                }
            }
            score += target;
            mark[target_idx] = true;
            if (target_idx > 0) mark[target_idx-1] = true;
            if (target_idx < nums.size()-1) mark[target_idx+1] = true;
        }
        return score;
    }
};

class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> nums2; // <origin_idx, value>
        vector<bool> mark(nums.size(), false);
        for (int i=0; i<nums.size(); i++) {
            nums2.push_back({i, nums[i]});
        }
        long long score = 0;
        sort(nums2.begin(), nums2.end(), cmp);
        for (int i=0; i<nums2.size(); i++) {
            if (!mark[nums2[i].first]) {
                score += nums2[i].second;
                mark[nums2[i].first] = true;
                if (nums2[i].first > 0) mark[nums2[i].first - 1] = true;
                if (nums2[i].first < nums2.size()-1) mark[nums2[i].first + 1] = true;
            }
        }
        return score;
    }
};