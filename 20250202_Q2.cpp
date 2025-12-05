#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int N = 0, W = 0, S = 0, E = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == 'N') N++;
            if (s[i] == 'W') W++;
            if (s[i] == 'S') S++;
            if (s[i] == 'E') E++;
        }
        char change, become;
        if (abs(N-S) > abs(W-E)) { // 先動南北
            if (N > S) {
                change = 'S';   
                become = 'N';
            }
            if (N < S) {
                change = 'N';
                become = 'S';
            }
        }

    }
};
/*
NSNSNSNSNNNNS
*/