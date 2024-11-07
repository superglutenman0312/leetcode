#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x==0 || x==1) return x;
        for (long long int i=2; i<=x; i++) {
            if (i*i > x) return i - 1;
        }
        return x;
    }
};

// binary search
class Solution {
public:
    int mySqrt(int x) {
        if (x==0 || x==1) return x;
        long long int left = 2, right = x, ans = 0;
        while (left <= right) {
            long long int mid = left + (right - left)/2;
            if (mid*mid == x) {
                ans = mid;
                break;
            }
            if (mid*mid >= x && (mid-1)*(mid-1) <= x) {
                ans  = mid - 1;
                break;
            }
            if ((mid-1)*(mid-1) < x) left = mid + 1;
            if ((mid-1)*(mid-1) > x) right = mid - 1;
        }
        return ans;
    }
};