#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> str;
        string sub_str = "", ans = "";
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ' ') sub_str += s[i];
            if (s[i] == ' ') {
                str.push_back(sub_str);
                sub_str = "";
            }
        }
        str.push_back(sub_str);
        for (int i=0; i<str.size(); i++) {
            reverse(str[i].begin(), str[i].end());
            ans += str[i];
            if (i < str.size()-1) ans += ' ';
        }
        return ans;
    }
};