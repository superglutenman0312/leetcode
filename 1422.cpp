#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        vector<int> zeros, ones;
        if (s[0] == '0') {
            zeros.push_back(1);
            ones.push_back(0);
        }
        else {
            ones.push_back(1);
            zeros.push_back(0);
        }
        for (int i=1; i<s.length(); i++) {
            int now1 = 0, now0 = 0;
            if (s[i] == '0') now0 = 1;
            else now1 = 1;
            zeros.push_back(zeros[i-1] + now0);
            ones.push_back(ones[i-1] + now1);
        }
        int ans = 0;
        for (int i=0; i<s.length()-1; i++) {
            ans = max(zeros[i] + ones[s.length()-1] - ones[i], ans);
        }
        return ans;
    }
};