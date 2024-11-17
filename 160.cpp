#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 用set
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> myset;
        ListNode* now = headA;
        if(headA == nullptr || headB == nullptr) return NULL;
        while(now != nullptr){
            myset.insert(now);
            now = now->next;
        }
        now = headB;
        while(now!=nullptr){
            if (myset.find(now) != myset.end()) return now;
            now = now->next;
        }
        return NULL;
    }
};

// 用雙指針
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            if (pA == nullptr) pA = headB;
            else pA = pA->next;
            if (pB == nullptr) pB = headA;
            else pB = pB->next;

            // pA = pA ? pA->next : headB;
            // pB = pB ? pB->next : headA;
        }
        return pA;
    }
};