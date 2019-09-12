#include <iostream>
#include <math.h>
using namespace std;
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL) return NULL;
        int sum1 = 0, sum2 = 0, sum = 0, carry = 0;
        ListNode *head = NULL, *temp = NULL;
        
        while(l1!=NULL || l2!=NULL){
            if(l1==NULL){
                sum1=0;
            }
            else{
                sum1 = l1->val;
            }
            if(l2==NULL){
                sum2=0;
            }
            else{
                sum2 = l2->val;
            }
            sum = sum1+sum2+carry;
            carry = sum/10;
            sum = sum%10;
            ListNode *newNode = new ListNode(sum);
            if(head==NULL){
                head = newNode;
                temp = newNode;
            }
            else{
                temp->next = newNode;
                temp = temp->next;
            }
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if(carry>0){
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return head;
    }
};