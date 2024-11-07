#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *now = head;
        set<ListNode *> st;
        while(now != NULL){
            if (st.find(now) == st.end()){
                st.insert(now);
                now = now->next;
            }
            else return true;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) return true;  // 有環
            slow = slow->next;       // 慢指針移動一步
            fast = fast->next->next; // 快指針移動兩步
        }
        return false; // 無環
    }
};