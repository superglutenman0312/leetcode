#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_big_char (char c) {
        return 'A' <= c && c <= 'Z'? true : false;
    }
    bool detectCapitalUse(string word) {
        int cases = 0;
        if (word.length() == 1) return true;
        if (is_big_char(word[0]) == false) { // 要整句都小寫
            cases = 0;
        }
        if (is_big_char(word[0]) == true) {
            if (is_big_char(word[1]) == true) { // 要整句全大寫
                cases = 1;
            }
            else cases = 2; // 開頭大寫，剩下小寫
        }
        for (int i=1; i<word.length(); i++) {
            if (cases == 0 || cases == 2) {
                if (is_big_char(word[i]) == true) return false;
            }
            else {
                if (is_big_char(word[i]) == false) return false;
            }
        }
        return true;
    }
};

