#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) return mid;
            if (nums[left] < nums[mid]) { // 在左邊
                if (nums[left] < target && nums[mid] < target) left = mid + 1;
                if (nums[left] < target && nums[mid] > target) right = mid + 1;
            }
            if (nums[left] < nums[mid]) { // 在左邊
                if (nums[right] > target && nums[mid] < target) left = mid + 1;
                if (nums[right] > target && nums[mid] > target) right = mid + 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 找到目标值，直接返回下标
            if (nums[mid] == target) return mid;
            // 检查左半部分是否有序
            if (nums[left] <= nums[mid]) {
                // 如果目标值在左半部分，移动 `right`
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            // 否则右半部分有序
            else {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};
// 4,5,6,7,0,1,2
// 5