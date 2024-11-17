#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // 分割s成word
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) words.push_back(word);
        if (words.size() != pattern.length()) return false;

        unordered_map<char, string> hash_table;
        for (int i=0; i<pattern.length(); i++) {
            if (hash_table.find(pattern[i]) != hash_table.end() && hash_table[pattern[i]] != words[i]) return false;
            hash_table[pattern[i]] = words[i];
        }
        
        unordered_map<string, char> check_table;
        for (auto i : hash_table) {
            if (check_table.find(i.second) != check_table.end() && check_table[i.second] != i.first) return false;
            check_table[i.second] = i.first;
        }
        return true;
    }
};