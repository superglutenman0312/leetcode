#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int cnt = 0;
        int cnt1 = 0, cnt2 = 0;
        while(1){
            if (cnt%2 == 0 && word1[cnt1]!='\0'){
                result += word1[cnt1++];
            }
            else if (cnt%2 == 1 && word2[cnt2]!='\0'){
                result += word2[cnt2++];
            }
            if (word1[cnt1]=='\0' && word2[cnt2]=='\0') break;
            cnt ++;
        }
        return result;
    }
};