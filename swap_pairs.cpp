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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *ans = swapPairs(head->next->next);
        int temp = head->val;
        head->val = head->next->val;
        head->next->val = temp;
        return head;
    }
};