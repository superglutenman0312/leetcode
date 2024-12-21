#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1, total = 9, start = 1;
        int tmp = n;
        while (tmp > digit * total) {
            tmp -= digit * total;
            digit++;
            total *= 10;
            start *= 10;
        }
        int true_num = start + (tmp-1)/digit;
        int idx = (tmp-1)%digit;
        string str_num = to_string(true_num);
        int ans = str_num[idx] - '0';
        return ans;
    }
};
// 3

// 200 - 9*1 = 191
// 191 - 90*2 = 11
// 11 - 1 = 10
// 10 / 3 = 103...1