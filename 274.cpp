#include<bits/stdc++.h>
using namespace std;

// pass[i]存共有幾篇論文超過i人cite
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int pass[1005] = {0};
        int cnt = 0;
        for (int i=0; i<1000; i++) {
            for (int j=0; j<citations.size(); j++) {
                if (citations[j] >= i) cnt++;
            }
            pass[i] = cnt;
            cnt = 0;
        }
        int ans;
        for (int i=1000; i>=0; i--) {
            if (pass[i] >= i) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

// dp[i][j]代表超過i人cite的論文有j篇
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0, len = citations.size();
        for (int i=0; i<len; i++) {
            if (citations[i] >= len - i) {
                ans = len - i;
                break;
            }
        }
        return ans;
    }
};

// [3,0,6,1,5]
// [0,1,3,5,6]