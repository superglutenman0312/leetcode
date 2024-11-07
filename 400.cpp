#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        string seqence;
        for(int i=1;i<=n;i++){
            seqence.append(to_string(i));
        }
        return (seqence[n-1] - '0');
    }
};

class Solution {
public:
    int findNthDigit(int n) {
        long long count = 9, digit = 1, start = 1;
        // 看n是幾位數
        while (n > count * digit) {
            n -= count * digit;
            digit++;            
            count *= 10;      
            start *= 10;       
        }
        // 看n屬於哪個數字
        start += (n - 1) / digit;
        // 看n在該數字的哪個位置
        string num = to_string(start);
        return num[(n - 1) % digit] - '0';
    }
};