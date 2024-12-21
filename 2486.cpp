#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) { // t短 s長
        int cnt = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == t[cnt]) cnt++;
        }
        return t.length() - cnt;
    }
};