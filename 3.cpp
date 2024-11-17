#include<bits/stdc++.h>
using namespace std;


// O(N^2logN)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0, max_length = 0;
        set<char> myset;
        for (int i=0; i<s.length(); i++){
            while(1){
                if ((myset.find(s[i+cnt]) != myset.end()) || (i+cnt) == s.length()){
                    max_length = max(max_length, cnt);
                    cnt = 0;
                    myset.clear();
                    break;
                }
                else {
                    myset.insert(s[i+cnt]);
                    cnt++;
                }
            }
        }
        return max_length;
    }
};

// 用hash
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = s.length()-1;
        unordered_map<char,int> hash_table;
        for (int i=0; i<s.length(); i++) {
            
        } 
    }
};