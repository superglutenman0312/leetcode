#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        int digit = 1, range = 26, tmp = columnNumber;
        string ans;
        // 得知它是digit位數
        while (tmp > range) {
            tmp -= range;
            digit++;
            range = pow(26, digit);
        }
        cout << digit<<" " << range<<"\n";
        int cnt = 0;
        range /= 26;
        while (digit--) {
            while (columnNumber > range) {
                columnNumber -= range;
                cnt++;
            }
            cout << cnt-1<<"\n";
            if (digit > 0) cnt--;
            ans += static_cast<char>('A' + cnt);
            range /= 26;
            cnt = 0;
        }
        return ans;
    }
};
// 52 -> AZ
// 53 -> BA
// 28 -> AB
// 701 -> ZY