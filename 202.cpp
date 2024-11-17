#include<bits/stdc++.h>
using namespace std;

int check(int n){
    int sum = 0;
    while (n) {
        sum += (n % 10)*(n % 10);
        n /= 10;
    }
    return sum;
}

class Solution {
public:
    bool isHappy(int n) {
        set<int> repeat;
        int now = n;
        repeat.insert(now);
        if (n == 1) return true;
        while (1) {
            now = check(now);
            if (now == 1) break;
            if (repeat.find(now) != repeat.end()) return false;
            else repeat.insert(now);
        }
        return true;
    }
};
