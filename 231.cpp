#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        if (n == 1 || n == 2) return true;
        if (n%2 == 0) return isPowerOfTwo(n/2);
        else return false;
    }
};

// 1 2 4 8 16
// 24