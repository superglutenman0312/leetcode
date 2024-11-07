#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *pre = head, *now = head->next;
    while (now) {
        ListNode *next_node = now->next;
        now->next = pre;
        pre = now;
        now = next_node;
    }
    head->next = NULL;
    return pre;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next) return head;
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *pre_left = dummy_head;
        for (int i=0; i<left-1; i++) pre_left = pre_left->next;
        ListNode *left_node = pre_left->next;
        ListNode *now = left_node, *pre = NULL;
        for (int i=0; i <= right-left; i++) {
            ListNode *next_node = now->next;
            now->next = pre;
            pre = now;
            now = next_node;
        }
        pre_left->next = pre;
        left_node->next = now;
        return dummy_head->next;
    }
};
// left = 2, right = 4
// X 1 2 3 4 5
// X 1 4 3 2 5