#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stackk;
        if(s.length() % 2) return false;
        for (int i=0; i<s.length(); i++){
            // 碰到左括號
            if (s[i] == '(') stackk.push(')');
            else if (s[i] == '[') stackk.push(']');
            else if (s[i] == '{') stackk.push('}');
            // 碰到右括號
            else {
                if (stackk.empty() || s[i] != stackk.top()) return false;
                else {
                    stackk.pop();
                    continue;
                }
            }
        }
        return stackk.empty()? true : false;
    }
};
// ([}}])