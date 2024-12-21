#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        for (int pos = address.find('.'); pos != string::npos; pos = address.find('.', pos + 3)) {
            cout << address << pos << "\n";
            address.replace(pos, 1, "[.]");
        }
        return address;
    }
};