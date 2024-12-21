#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, tmp = x;
        while (tmp) {
            sum += tmp%10;
            tmp /= 10;
        }
        return x%sum == 0 ? sum : -1;
    }
};