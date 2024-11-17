#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char to_lower(char c) {
        return c - 'A' + 'a';
    }
    bool isPalindrome(string s) {
        string real_str;
        for (int i=0; i<s.length(); i++){
            if('a' <= s[i] && s[i] <= 'z') real_str += s[i];
            if('A' <= s[i] && s[i] <= 'Z') real_str += to_lower(s[i]);
            if('0' <= s[i] && s[i] <= '9') real_str += s[i];
        }
        if (real_str.empty()) return true;
        for (int i=0; i<real_str.length(); i++){
            int j = real_str.length() - i - 1;
            if (real_str[i] == real_str[j]) continue;
            return false;
        }
        return true;
    }
};