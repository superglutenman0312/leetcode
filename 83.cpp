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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *now = head;
        set<int> myset;
        // 看head是否存在
        if (now != NULL) myset.insert(now->val);
        else return head;
        while(now->next != NULL){
            // 沒看過的val，保留node
            if( myset.find(now->next->val) == myset.end() ){
                myset.insert(now->next->val);
                now = now->next;
            }
            // 有看過的val，刪除node
            else{
                ListNode *del = now->next;
                now->next = now->next->next;
                delete(del);
            }

        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *now = head;
        while(now!=NULL && now->next!=NULL){
            // 若後面node的val和前面node的val相同，則刪除後面的node
            if(now->val == now->next->val) {
                ListNode *del = now->next;
                now->next = now->next->next;
                delete(del);
            }
            else now = now->next;
        }
        return head;
    }
};
