#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans = {-1, -1};
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return ans;
        int left = 0, right = nums.size()-1, idx = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                idx = mid;
                break;
            }
        }
        cout << idx;
        left = idx, right = idx;
        while (left >= 0) {
            if (nums[left] == target) ans[0] = left--;
            else break;
        }
        while (right < nums.size()) {
            if (nums[right] == target) ans[1] = right++;
            else break;
        }
        return ans;
    }
};

// GPT
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if (nums.empty()) return ans;
        
        // 找到 target 的左边界
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // 检查左边界是否存在
        if (left >= nums.size() || nums[left] != target) return ans;
        ans[0] = left;
        
        // 找到 target 的右边界
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        ans[1] = right;
        
        return ans;
    }
};
