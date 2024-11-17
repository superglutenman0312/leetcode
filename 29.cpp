#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long cnt = 0, ll_dividend = dividend, ll_divisor = divisor;
        if (ll_dividend >= 0 && ll_divisor > 0 || ll_dividend < 0 && ll_divisor < 0){ // 同號
            ll_dividend = abs(ll_dividend);
            ll_divisor = abs(ll_divisor);
            while (ll_dividend >= ll_divisor){
                cnt++;
                ll_dividend -= ll_divisor;
            }
        }
        else{ // 異號
            ll_dividend = abs(ll_dividend);
            ll_divisor = -1 * abs(ll_divisor);
            while (ll_dividend >= abs(ll_divisor)){
                cnt--;
                ll_dividend -= abs(ll_divisor);
            }
        }
        if (cnt > 2147483647) cnt = 2147483647;
        if (cnt < -2147483648) cnt = -2147483648;
        return cnt;
    }
};

// 7 / -3 = -2.333 -> -2
// -7 / 3 = -2.333