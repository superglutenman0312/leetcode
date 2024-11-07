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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy_head = new ListNode();
        ListNode *pre = dummy_head;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                pre->next = list1;
                pre = list1;
                list1 = list1->next;
            }
            else if(list1->val > list2->val){
                pre->next = list2;
                pre = list2;
                list2 = list2->next;
            }
        }
        // 一條是NULL後，把另一條剩的node補回來
        pre->next = list1==NULL? list2 : list1;
        return dummy_head->next;
    }
};
// dh 1 1 2 3 4 