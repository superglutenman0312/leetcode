#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        vector<int> tmp1 = arr; // lower
        vector<int> tmp2 = arr; // greater
        vector<int> tmp3 = brr;
        vector<int> tmp4 = brr;
        long long ans1 = 0, diff1a = 0, diff2a = 0, diff1b = 0, diff2b = 0, ans2 = 0;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp3.begin(), tmp3.end());
        sort(tmp2.begin(), tmp2.end(), greater<int>());
        sort(tmp4.begin(), tmp4.end(), greater<int>());
        for (int i=0; i<arr.size(); i++) {
            if (tmp1[i] != arr[i]) diff1a ++;
            if (tmp2[i] != arr[i]) diff2a ++;
            if (tmp3[i] != brr[i]) diff1b ++;
            if (tmp4[i] != brr[i]) diff2b ++;
        }
        if (diff1a < diff2a || diff1b << diff2b) { // lower good, use tmp1 & tmp3
            for (int i=0; i<arr.size(); i++) {
                ans1 += abs(tmp1[i] - tmp3[i]);
            }
            if (diff1a || diff1b) ans1 += (max(diff1a, diff1b)-1)*k;
        }
        else {
            for (int i=0; i<arr.size(); i++) {
                ans1 += abs(tmp2[i] - tmp4[i]);
            }
            if (diff2a || diff2b) ans1 += (max(diff2a, diff2b)-1)*k;
        }
        for (int i=0; i<arr.size(); i++) {
            ans2 += abs(arr[i] - brr[i]);
        }
        return min(ans1, ans2);
    }
};

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        vector<int> tmp1 = arr; // lower
        vector<int> tmp2 = brr; // greater
        long long ans1 = 0, diff = 0;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        for (int i=0; i<arr.size(); i++) {
            if (tmp1[i] != arr[i]) diff ++;
        }
        
        return ans1;
    }
};

/*
[9 5 -7]
[7 -2 -5]

[-7 9 5]
[-7 5 9]
[-5 -2 7]

[8,-1]
[4,-6]

[-1 8]
[-6 4]
5 + 4

-7 9 5
9 5 -7
7 -2 -5

[3,10]
[4,3]

[3 10]
[3  4]

[10 3]


*/