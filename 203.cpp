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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode *dummyhead = new ListNode(0, head);
        ListNode *pre = dummyhead, *now = head;
        while (now) {
            if (now->val == val) {
                pre->next = now->next;
                now = now->next;
            }
            else {
                pre = now;
                now = now->next;
            }
        }
        return dummyhead->next;
    }
};