#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        int digit = 1;
        if (num < 0) {
            num *= -1;
            ans += "-";
        }
        while (num - pow(7,digit) >= 0) {
            digit++;
        }
        int now_gap = pow(7, --digit);
        while (num > 0) {
            int val = num/now_gap;
            ans += ('0' + val);
            num -= now_gap * val;
            now_gap /= 7;
        }
        while (now_gap != 0) {
            ans += '0';
            now_gap /= 7;
        }
        return ans;
    }
};
// 107
// 212