#include<bits/stdc++.h>
using namespace std;

// O(n*m) TLE
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int next = 0, cnt = 0;
        for (int i=0; i<g.size(); i++){
            for (int j=next; j<s.size(); j++){
                if (g[i] <= s[j]) {
                    cnt++;
                    next = j+1;
                    if (next >= s.size()) return cnt;
                    break;
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_idx = 0, s_idx = 0, cnt = 0;
        while (g_idx < g.size() && s_idx < s.size()) {
            if (g[g_idx] <= s[s_idx]) {
                cnt++;
                g_idx++;
            } 
            s_idx++;
        }
        return cnt;
    }
};

// 2 2 2 2
// 1 1 1 8