#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num == 1) return false;
        for (int i=1; i<=sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                if (i != 1) sum += num/i;
            }
        }
        return sum == num ? true : false;
    }
};