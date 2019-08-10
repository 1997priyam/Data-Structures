#include<iostream> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
  };

ListNode* deleteDuplicates(ListNode* A) {
    ListNode* head = NULL;
    ListNode* temp = A;
    ListNode* ans = NULL;
    while(temp != NULL){
        int data = temp->val;
        if(temp->next==NULL){
            if(head==NULL){
                head = temp;
                if(ans==NULL) ans=head;
            }
            else{
                head->next = temp;
                head = head->next;
            }
            if(head!=NULL)
            head->next = NULL;
            return ans;
        }
        if(temp->val == temp->next->val){
            while(temp->val == data){
                temp = temp->next;
                if(temp==NULL){
                    if(head!=NULL)
                    head->next = NULL;
                    return ans;
                } 
            }
        }
        else{
            if(head==NULL){
                head = temp;
                ans = head;
            }
            else{
                head->next = temp;
                head = head->next;
            }
            temp = temp->next;
        }
    }
    if(head!=NULL)
    head->next = NULL;
    return ans;
}