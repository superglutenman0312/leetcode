#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common_str, base = strs[0];
        int idx = 0, max_idx = base.size();
        for(int i=1; i<strs.size(); i++){
            auto mismathch_pair = mismatch(base.begin(), base.end(), strs[i].begin());
            idx = mismathch_pair.first - base.begin();
            max_idx = min(idx, max_idx);
        }
        common_str = base.substr(0, max_idx);
        return common_str;
    }
};
/*
abcde
abc
abcdefg
*/