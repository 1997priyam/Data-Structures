#include<iostream> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
  };

ListNode* deleteDuplicates(ListNode* A) {
    ListNode* temp = A;
    while(temp->next!=NULL){
        if(temp->val == (temp->next)->val){
            temp->next = (temp->next)->next;
        }
        else{
            temp = temp->next;
        }
    }
    return A;
}