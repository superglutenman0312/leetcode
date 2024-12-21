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

// 用hash實作sliding window算法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_tb;
        int left = 0, cnt = 0;
        for (int right=0; right<s.length(); right++) {
            hash_tb[s[right]]++;
            while (hash_tb[s[right]] > 1) {
                hash_tb[s[left]]--;
                left++;
            }
            cnt = max(cnt, right-left+1);
        }
        return cnt;
    }
};