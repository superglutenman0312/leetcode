#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash_table;
        char c;
        for (int i=0; i<s.length(); i++) {
            hash_table[s[i]]++;
        }
        for (int i=0; i<t.length(); i++) {
            hash_table[t[i]]--;
            if (hash_table[t[i]] < 0) c = t[i];
        }
        return c;
    }
};