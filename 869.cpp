#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int, int> num_cnt;
        while (n != 0) {
            num_cnt[n % 10]++;
            n /= 10;
        }
        unordered_map<int, int> pow2_cnt;
        for (int i=0; i<30; i++) {
            pow2_cnt.clear();
            int pow2 = pow(2, i);
            while (pow2 != 0) {
                pow2_cnt[pow2 % 10]++;
                pow2 /= 10;
            }
            if (num_cnt == pow2_cnt) return true;
        }
        return false;
    }
};