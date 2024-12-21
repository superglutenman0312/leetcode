#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse_int(int num) {
        int sum = 0;
        while (num > 0){
            sum *= 10;
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    bool sumOfNumberAndReverse(int num) {
        if (num == 0) return true;
        for (int i=num; i>=(num/2-1); i--) {
            int rev = reverse_int(i);
            if (i + rev == num) return true;
        }
        return false;
    }
};