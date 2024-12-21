#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string long_str, short_str, str="";
        if (str1.length() >= str2.length()) {
            long_str = str1;
            short_str = str2;
        }
        else {
            long_str = str2;
            short_str = str1;
        }
        int len = short_str.length();
        for (int i=0; i<len; i++) {
            while (str.length() < long_str.length()) {
                str.append(short_str);
            }
            if (str == long_str) return short_str;
            short_str.pop_back();
            str = ""; 
        }
        return short_str;    
    }
};