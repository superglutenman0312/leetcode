#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash_mp1, hash_mp2;
        for (int i=0; i<s.length(); i++) {
            if (hash_mp1.find(s[i]) != hash_mp1.end() && hash_mp1[s[i]] != t[i]) return false;
            if (hash_mp1.find(s[i]) == hash_mp1.end()) hash_mp1[s[i]] = t[i];
        }
        return true;
    }
};