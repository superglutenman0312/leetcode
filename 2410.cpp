#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int idx = 0;
        for (int i=0; i<trainers.size(); i++) {
            if (trainers[i] >= players[idx]) idx++;
            if (idx >= players.size()) break;
        }
        return idx;
    }
};