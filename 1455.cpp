#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        stringstream ss;
        string word;
        ss << sentence;
        while (ss >> word) {
            words.push_back(word);
        }
        for (int i=0; i<words.size(); i++) {
            if (words[i].find(searchWord) == 0) return i+1;
        }
        return -1;
    }
};