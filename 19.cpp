#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        int len = 1;
        ListNode *now = head, *pre = head;
        while (now) {
            len++;
            now = now->next;
        }
        int pre_to_delete = --len - n;
        if (pre_to_delete == 0) return head->next;
        now = head;
        len = 1;
        while (now) {
            if (len == pre_to_delete) now->next = now->next->next;
            len++;
            now = now->next;
        }
        return head;
    }
};