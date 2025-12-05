#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y;
        int ans = 0;
        while (num) {
            if (num % 2) ans++;
            num /= 2;
        }
        return ans;
    }
};