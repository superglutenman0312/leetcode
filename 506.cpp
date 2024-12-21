#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<int> score_sort = score;
        unordered_map<int,int> hash_tb;
        sort(score_sort.begin(), score_sort.end(), greater<int>());
        for (int i=0; i<score_sort.size(); i++) {
            hash_tb[score_sort[i]] = i+1;
        }
        
        string rank_str = "";
        for (int i=0; i<score.size(); i++) {
            int rank = hash_tb[score[i]];
            if (rank <= 3) {
                if (rank == 1) rank_str = "Gold Medal";
                if (rank == 2) rank_str = "Silver Medal";
                if (rank == 3) rank_str = "Bronze Medal";
            }
            else rank_str = to_string(rank);
            ans.push_back(rank_str);
            rank_str = "";
        }
        return ans;
    }
};