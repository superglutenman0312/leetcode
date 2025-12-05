#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int, int> freq;
        int odd_max = 0, even_max = 0, odd_min = 1e9, even_min = 1e9;
        for (int i=0; i<s.length(); i++) {
            freq[s[i]]++;
        }
        for (auto i : freq) {
            if (i.second%2) {
                odd_max = max(odd_max, i.second);
                odd_min = min(odd_min, i.second);
            }
            if (i.second%2 == 0) {
                even_max = max(even_max, i.second);
                even_min = min(even_min, i.second);
            }
        }
        // if (odd_max > even_max) return odd_max - even_max;
        return odd_max - even_min;
    }
};