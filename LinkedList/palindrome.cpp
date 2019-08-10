#include<iostream>
#include<stack> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
  };

int isPalindrome(ListNode* A){
    ListNode* temp = A;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->val);
        temp = temp->next;
    }
    ListNode* temp2 = A;
    while(temp2!=NULL){
        if(st.top()!=temp2->val){
            return 0;
        }
        else{
            st.pop();
            temp2 = temp2->next;
        }
    }
    return 1;
}