#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // (values[i] + i) + (values[j] - j)
        int a = values[0]; // (values[i] + i) = a
        int ans = 0;
        for (int i=1; i<values.size(); i++) {
            ans = max(ans, a + values[i] - i);
            a = max(a, values[i] + i);
        }
        return ans;
    }
};