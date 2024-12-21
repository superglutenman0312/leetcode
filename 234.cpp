#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// use vector
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode *now = head;
        while (now) {
            arr.push_back(now->val);
            now = now->next;
        }
        for (int i=0; i<arr.size(); i++) {
            if (arr[i] != arr[arr.size()-1-i]) return false;
        }
        return true;
    }
};