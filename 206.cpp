#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 用vector
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        vector<ListNode*> vec;
        ListNode *now = head;
        while (now) {
            vec.push_back(now);
            now = now->next;
        }
        head = vec.back();
        ListNode *pre = head;
        vec.pop_back();
        while (!vec.empty()) {
            now = vec.back();
            vec.pop_back();
            pre->next = now;
            pre = now;
        }
        pre->next = NULL;
        return head;
    }
};

// in-place reverse
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};