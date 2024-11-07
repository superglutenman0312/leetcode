#include<bits/stdc++.h>
using namespace std;

// 用hash
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash_table;
        for (int i=0; i<magazine.size(); i++) {
            hash_table[magazine[i]]++;
        }
        for (int i=0; i<ransomNote.size(); i++) {
            hash_table[ransomNote[i]]--;
            if (hash_table[ransomNote[i]] < 0) return false;
        }
        return true;
    }
};

// 改用array會更快，因為只存a-z，所以可以開size = 26的array當hash_table用