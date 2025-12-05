#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long int digit = 1, total_num = 9, start = 1;
        long long int tmp = n;
        while (tmp > digit * total_num) {
            tmp -= digit * total_num;
            digit++;
            total_num *= 10;
            start *= 10;
        }
        long long int true_num = start + (tmp-1)/digit;
        long long int idx = (tmp-1)%digit;
        string str_num = to_string(true_num);
        long long int ans = str_num[idx] - '0';
        return ans;
    }
};
// 3

// 200 - 9*1 = 191
// 191 - 90*2 = 11
// 11 - 1 = 10
// 10 / 3 = 103...1