#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool negative = false;
        if (s[0] == '-') {
            negative = true;
            reverse(s.begin()+1, s.end());
        }
    }
};