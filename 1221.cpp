#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        unordered_map<char, int> hash_tb;
        int ans = 0;
        for (int i=0; i<s.length(); i++) {
            hash_tb[s[i]]++;
            if (hash_tb['L'] == hash_tb['R']) ans++;
        }
        return ans;
    }
};