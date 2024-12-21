#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> hash_mp1;
        unordered_map<char, int> hash_mp2;
        int cnt = 0;
        bool flag = true;
        for (int i=0; i<s.size(); i++) {
            hash_mp1[s[i]]++;
        }
        for (int i=0; i<target.size(); i++) {
            hash_mp2[target[i]]++;
        }
        while (1) {
            for (auto i : hash_mp2) {
                if (hash_mp1.find(i.first) == hash_mp1.end() || hash_mp1[i.first] < hash_mp2[i.first]) {
                    flag = false;
                    break;
                }
                hash_mp1[i.first] -= hash_mp2[i.first];
            }
            if (flag) cnt++;
            else break;
        }
        return cnt;
    }
};