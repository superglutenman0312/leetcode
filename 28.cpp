#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle) == string::npos ? -1 : haystack.find(needle);
    }
};