#include<bits/stdc++.h>
using namespace std;

 // O(n)太慢，會TLE
class Solution {
public:
    double myPow(double x, int n) {
        long long int N = n;
        double ans = 1;
        if (N == 0 || x == 1) return 1;
        if (x == -1) return N%2? -1 : 1;
        if (N < 0) {
            N = -1 * N;
            x = 1 / x;
        }
        while (N--) ans *= x;
        return ans;
    }
};

// 快速冪
class Solution {
public:
    double myPow(double x, int n) {
        long long int N = n;
        if (N == 0 || x == 1) return 1;
        if (x == -1) return N%2? -1 : 1;
        if (N < 0) {
            N = -1 * N;
            x = 1 / x;
        }
        double ans = 1, cur_product = x;
        while (N > 0){
            if (N % 2) ans *= cur_product;
            cur_product *= cur_product;
            N /= 2;
        }
        return ans;
    }
};
// 2^10
// 10 -> 2 
// 1 2 4 8 16