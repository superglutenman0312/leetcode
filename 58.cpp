#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        vector<string> tokens;
        string token;
        int cnt = 0;
        
        while (iss >> token){
            tokens.push_back(token);
        }
        token = tokens[tokens.size()-1];
        return token.length();
    }
};