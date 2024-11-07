#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cnt = 0, temp = 0, result = 0;
        while(cnt != gain.size()){
            temp += gain[cnt++];
            result = max(temp, result);
        }
        return result;
    }
};