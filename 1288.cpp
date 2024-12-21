#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmpp(const vector<int>& a, const vector<int>& b) {
        return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmpp);
        int ans = intervals.size();
        for (int i=intervals.size()-1; i>=0; i--) {
            int idx = i - 1;
            while (idx >= 0) {
                if (intervals[i][1] <= intervals[idx][1]) {
                    ans--;
                    break;
                }
                idx--;
            }
        }
        return ans;
    }
};
/*
1 4
2 8
3 6
10 12

1 4
3 6
2 8
*/