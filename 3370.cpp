#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        long long int pre_mod = 1;
        long long int mod = 1;
        if (n == 1) return 1;
        for (long long int i=1; i<11; i++) {
            pre_mod = mod;
            long long int mod = pow(2,i);
            if (n == mod) return mod*2 - 1;
            if (pre_mod < n && n <= mod) {
                return mod-1;
            }
        }
        return mod-1;
    }
};
