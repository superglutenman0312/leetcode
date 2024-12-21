#include<bits/stdc++.h>
using namespace std;

// 由前往後覆蓋
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0, ptr2 = 0, now = 0;
        vector<int> nums3 = nums1;
        while (1) {
            if (ptr1 >= m && ptr2 >= n) break;
            if (ptr1 >= m && ptr2 < n) {
                nums3[now++] = nums2[ptr2++];
            }
            if (ptr1 < m && ptr2 >= n) {
                nums3[now++] = nums1[ptr1++];
            }
            if (ptr1 < m && ptr2 < n && nums1[ptr1] <= nums2[ptr2]) {
                nums3[now++] = nums1[ptr1++];
            }
            if (ptr1 < m && ptr2 < n && nums1[ptr1] > nums2[ptr2]) {
                nums3[now++] = nums2[ptr2++];
            }
        }
        nums1 = nums3;
        return;
    }
};

// 由後往前覆蓋
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = nums1.size()-1, ptr2 = nums2.size()-1, now = ptr1;
        while (1) {
            if (ptr1 < 0 && ptr2 < 0) break;
            if (ptr1 < 0 && ptr2 >= 0) {
                nums1[now--] = nums2[ptr2--];
            }
            if (ptr1 >= 0 && ptr2 < 0) {
                nums1[now--] = nums1[ptr1--];
            }
            if (ptr1 >= 0 && ptr2 >= 0 && nums1[ptr1] > nums2[ptr2]) {
                nums1[now--] = nums1[ptr1--];
            }
            if (ptr1 >= 0 && ptr2 >= 0 && nums1[ptr1] <= nums2[ptr2]) {
                nums1[now--] = nums2[ptr2--];
            }
        }
        return;
    }
};