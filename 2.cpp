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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, l1_val, l2_val;
        ListNode *head = new ListNode();
        ListNode *pre = head;
        while(l1!=NULL || l2!=NULL || carry!=0){
            l1_val = l1!=NULL? l1->val : 0;
            l2_val = l2!=NULL? l2->val : 0;
            int sum = l1_val + l2_val + carry;
            carry = sum/10;
            sum %= 10;
            ListNode *now = new ListNode(sum);
            pre->next = now;
            pre = now;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        return head->next;
    }
};















//失敗
class Solution {
public:
    long long list_to_num(ListNode* list){
        string list_num;
        while(list != NULL){
            list_num.append(to_string(list->val));
            list = list->next;
        }
        reverse(list_num.begin(), list_num.end());
        return stoi(list_num);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long num1 = 0, num2 = 0, sum = 0;
        string ans_str;
        num1 = list_to_num(l1);
        num2 = list_to_num(l2);
        sum = num1 + num2; //342 + 465 = 807
        ans_str = to_string(sum); //ans_str = "807"
        reverse(ans_str.begin(), ans_str.end()); //ans_str = "708"
        ListNode *new_head = new ListNode(ans_str[0]-'0');
        ListNode *pre = new ListNode();
        pre = new_head;
        long long cnt = 1;
        while(cnt != ans_str.size()){
            ListNode *now = new ListNode(ans_str[cnt++]-'0');
            pre->next = now;
            pre = now;
        }
        return new_head;
    }
};
