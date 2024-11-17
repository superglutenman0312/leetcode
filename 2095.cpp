#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 看兩次
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int length = 0, delete_idx = 0, now_idx = 0;
        ListNode *now = head;
        if (now->next == nullptr) return NULL;
        while (now) {
            length++;
            now = now->next;
        }        
        delete_idx = length / 2;
        now = head;
        while (now) {
            if (now_idx == delete_idx-1) {
                now->next = now->next->next;
            }
            now_idx++;
            now = now->next;
        }
        return head;
    }
};

// 快慢指針
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return NULL;
        ListNode *fast = head, *slow = head, *pre = head;
        while (1) {
            if (fast->next == NULL){
                // 慢指針要刪
                pre->next = slow->next;
                break;
            }
            if (fast->next->next == NULL) {
                // 慢指針的下一個要刪
                slow->next = slow->next->next;
                break;
            }
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        return head;
    }
};