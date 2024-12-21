#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_out(int n, vector<int>& pos) {
        if (pos[1] < 0 || pos[1] >= n) return true;
        if (pos[0] < 0 || pos[0] >= n) return true;
        return false;
    }
    void move(char c, vector<int>& pos) {
        if (c == 'R') pos[1] += 1;
        if (c == 'D') pos[0] += 1;
        if (c == 'L') pos[1] -= 1;
        if (c == 'U') pos[0] -= 1;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for (int i=0; i<s.length(); i++) {
            vector<int> mimic = startPos;
            int cnt = 0;
            for (int j=i; j<s.length(); j++) {
                char c = s[j];
                move(c, mimic);
                if (is_out(n, mimic)) break;
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

// 用row col
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for (int i=0; i<s.length(); i++) {
            int row = startPos[1], col = startPos[0];
            int cnt = 0;
            for (int j=i; j<s.length(); j++) {
                char c = s[j];
                if (c == 'R') row += 1;
                if (c == 'D') col += 1;
                if (c == 'L') row -= 1;
                if (c == 'U') col -= 1;
                if (row < 0 || row >= n || col < 0 || col >= n) break;
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};