#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans;
        while (!num1.empty() || !num2.empty()) {
            int a = 0, b = 0;
            if (!num1.empty()) {
                a = num1.back() - '0';
                num1.pop_back();
            }
            if (!num2.empty()) {
                b = num2.back() - '0';
                num2.pop_back();
            }
            int sum = a + b + carry;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            else carry = 0;
            ans.append(to_string(sum));
        }
        if (carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};