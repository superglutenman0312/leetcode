#include<bits/stdc++.h>
using namespace std;

// 暴力解 N2 (TLE)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right;
        int ans = 0, now = 0;
        for (right = 0; right<height.size(); right++) {
            for (left = 0; left<right; left++) {
                now = min(height[left], height[right]) * (right - left);
                if (now > ans) ans = now;
            }
        }
        return ans;
    }
};

// two pointer
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int ans = 0, now = 0;
        while (left < right) {
            now = min(height[left], height[right]) * (right - left);
            ans = max(ans, now);
            if (height[left] <= height[right]) left++;
            else right--;
        }
        return ans;
    }
};