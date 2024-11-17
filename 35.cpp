#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // binary search
        int left = 0, right = nums.size()-1, mid = (nums.size()-1)/2;
        cout << left << right << mid;
        if (target > nums[right]) return right + 1;
        if (target < nums[left]) return 0;        
        while(1){
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) {
                right = mid;
                mid = (left + right) / 2;
            }
            if (target > nums[mid]){
                left = mid;
                mid = (left + right) / 2;
            }
            if (right == left + 1) return right;
        }
        return 0;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // binary search
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;  // 中间索引
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;  // target 在右边
            else right = mid - 1;  // target 在左边
        }
        // 如果没有找到，返回应该插入的位置
        return left;
    }
};