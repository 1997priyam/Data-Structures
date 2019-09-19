#include<iostream>
using namespace std;
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
    //   ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *ans = head;
        if(!l1) return l2;
        if(!l2) return l1;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                head->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                head->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            head = head->next;
            if(l1==NULL){
                head->next = l2;
            }
            if(l2==NULL){
                head->next = l1;
            }
        }
        return ans->next;
    }
};