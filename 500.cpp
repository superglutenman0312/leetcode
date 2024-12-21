#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> s1 = {'q','w','e','r','t','y','u','i','o','p'};
        set<char> s2 = {'a','s','d','f','g','h','j','k','l'};
        set<char> s3 = {'z','x','c','v','b','n','m'};
        vector<string> ans;
        bool flag = true;
        for (int i=0; i<words.size(); i++) {
            flag = true;
            set<char> cur_set;
            for (int j=0; j<words[i].length(); j++) {
                char c = words[i][j];
                if ('A' <= c && c <= 'Z') c = c - 'A' + 'a';
                if (j == 0) {
                    if (s1.find(c) != s1.end()) cur_set = s1;
                    else if (s2.find(c) != s2.end()) cur_set = s2;
                    else cur_set = s3;
                }
                if (cur_set.find(c) == cur_set.end()) {
                    flag = false;
                    cout << "words["<<i<<"]["<<j<<"] false\n";
                    break;
                }
            }
            if (flag) ans.push_back(words[i]);
        }
        return ans;
    }
};
// Alaska