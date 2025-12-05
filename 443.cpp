#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        char now = chars[0];
        int cnt = 1;
        for (int i=1; i<chars.size(); i++) {
            if (chars[i] == now) cnt++;
            else {
                s += now;
                if (cnt > 1) s.append(to_string(cnt));
                now = chars[i];
                cnt = 1;
            }
        }
        s += now;
        if (cnt > 1) s.append(to_string(cnt));
        chars.clear();
        for (int i=0; i<s.length(); i++) {
            chars.push_back(s[i]);
        }
        return s.length();
    }
};