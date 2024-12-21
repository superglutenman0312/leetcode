#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string long_str, short_str, ans;
        int carry = 0, x, y;
        if (a.length() >= b.length()) {
            long_str = a;
            short_str = b;
        }
        else {
            long_str = b;
            short_str = a;
        }
        int long_idx = long_str.length() - 1;
        int short_idx = short_str.length() - 1;
        for (int i=0; i<long_str.length(); i++) {
            x = long_str[long_idx--] - '0';
            if (i < short_str.length()) y = short_str[short_idx--] - '0';
            else y = 0;
            if (x + y + carry == 3) {
                ans += '1';
                carry = 1;
            }
            else if (x + y + carry == 2) {
                ans += '0';
                carry = 1;
            }
            else if (x + y + carry == 1) {
                ans += '1';
                carry = 0;
            }
            else if (x + y + carry == 0) {
                ans += '0';
                carry = 0;
            }
        }
        if (carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// 1010
// 1011
//10101