#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hash_table;
        for (int i=0; i<s.length(); i++) {
            hash_table[s[i]]++; 
        }
        for (int i=0; i<s.length(); i++) {
            if (hash_table[s[i]] == 1) return i;
        }
        return -1;
    }
};