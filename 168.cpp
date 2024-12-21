#include<bits/stdc++.h>
using namespace std;

// 耖你媽，虧我搞那麼久，然後RE，去你的
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
        int cnt = 0;
        range /= 26;
        while (digit--) {
            while (columnNumber > range) {
                columnNumber -= range;
                cnt++;
            }
            if (digit > 0) cnt--;
            ans += static_cast<char>('A' + cnt);
            range /= 26;
            cnt = 0;
        }
        return ans;
    }
};

// GPT的
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            columnNumber--;  // 调整范围到 0 到 25
            char ch = 'A' + (columnNumber % 26);
            ans = ch + ans;  // 逐次添加到结果前面
            columnNumber /= 26;
        }
        return ans;
    }
};


// 52 -> AZ
// 53 -> BA
// 28 -> AB
// 701 -> ZY