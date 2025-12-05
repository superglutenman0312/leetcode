#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        if (p.length() == 1) return true;
        int left = 0, right = s.length()-1, l_end = 0, r_begin = 0, star_idx = 0;
        bool flag1 = false, flag2 = false;
        for (int i=0; i<p.length(); i++) {
            if (p[i] == '*') {
                l_end = i-1;
                r_begin = i+1;
                star_idx = i;
                break;
            }
        }
        if (star_idx > 0) {
            for (int i=0; i<s.length(); i++) {
                left = i;
                for (int j=0; j<=l_end; j++) {
                    if (left >= s.length() || s[left++] != p[j]) break;
                    if (j == l_end) flag1 = true;
                }
                if (flag1) {
                    left--;
                    break;
                }
            }
        }
        if (star_idx < p.length()-1) {
            for (int i=s.length()-1; i>=0; i--) {
                right = i;
                for (int j=p.length()-1; j>=r_begin; j--) {
                    if (right < 0 || s[right--] != p[j]) break;
                    if (j == r_begin) flag2 = true;
                }
                if (flag2) {
                    right++;
                    break;
                }
            }
        }
        if (flag1 && flag2 && left < right) return true;
        if (star_idx == 0 && flag2) return true;
        if (star_idx == p.length()-1 && flag1) return true;
        return false;
    }
};

/*
luck
*u

"kvb"
"k*v"



"leetcode"
"ee*e"
"car"
"c*v"
"luck"
"u*"
"kvb"
"k*v"
"nrnrs"
"*nn"
*/