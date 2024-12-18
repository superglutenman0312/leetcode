#include<bits/stdc++.h>
using namespace std;

// recursuve
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        return fib(n-1) + fib(n-2);
    }
};

// table
class Solution {
public:
    unordered_map<int,int> table;
    int fib(int n) {
        table[0] = 0;
        table[1] = 1;
        for (int i=2; i<=n; i++) {
            table[i] = table[i-1] + table[i-2];
        }
        return table[n];
    }
};