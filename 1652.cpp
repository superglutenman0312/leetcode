#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> arr, prefix;
        int cnt = 3, len = code.size();
        while (cnt--) {
            for (int i=0; i<len; i++) {
                arr.push_back(code[i]);
            }
        }
        prefix.push_back(arr[0]);
        for (int i=1; i<arr.size(); i++) {
            prefix.push_back(prefix[i-1] + arr[i]);
        }
        for (int i=0; i<len; i++) {
            if (k > 0) code[i] = prefix[len+k+i] - prefix[len+i];
            else code[i] = prefix[len+i-1] - prefix[len+k+i-1];
        }
        return code;
    }
};

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> arr, prefix;
        int cnt = 3, len = code.size();
        while (cnt--) {
            for (int i=0; i<len; i++) {
                arr.push_back(code[i]);
            }
        }
        prefix.push_back(arr[0]);
        while (cnt--) {
            for (int i=1; i<arr.size(); i++) {
                prefix.push_back(prefix[i-1] + arr[i]);
            }
        }
        for (int i=0; i<len; i++) {
            if (k > 0) code[i] = prefix[len+k+i] - prefix[len+i];
            else code[i] = prefix[len+i-1] - prefix[len+k+i-1];
        }
        return code;
    }
};
/*
5 7 1 4, 5 7 1 4, 5 7 1 4
12,10,16,13
2 4 9 3, 2 4 9 3, 2 4 9 3
12,5,6,13
*/