#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        vector<bool> visit(nums.size(), false);
        stack<int> st;
        set<int> sett;
        visit[0] = true;
        st.push(0);
        sett.insert(nums[0]);
        while (!st.empty()) {
            int target_node = st.top();
            st.pop();
            visit[target_node] = true;
            
            for (int i=0; i<edges.size(); i++) {
                if (edges[i][0] == target_node && !visit[edges[i][1]]) st.push(edges[i][1]);
            }

        }
    }
};