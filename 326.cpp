#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        if (n == 1 || n == 3) return true;
        if (n%3 == 0) return isPowerOfThree(n/3);
        else return false;
    }
};

// 1 3 9 27 81
// 24