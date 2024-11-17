#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total_time = 0;
        for (int i=0; i<timeSeries.size(); i++){
            //reset poison
            if ((i+1)!=timeSeries.size() && (timeSeries[i] + duration > timeSeries[i+1])){
                total_time += timeSeries[i+1] - timeSeries[i];
            }
            else total_time += duration;
        }
        return total_time;
    }
};