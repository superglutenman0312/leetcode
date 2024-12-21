#include<bits/stdc++.h>
using namespace std;

// 跟168姊妹題，但這題簡單多了
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0, len = columnTitle.length();
        for (int i=0; i<len; i++) {
            ans += pow(26, len-i-1) * (columnTitle[i]-'A'+1);
        }
        return ans;
    }
};