#include<iostream> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode* reverse(ListNode* A, int m, int n){
    ListNode* head = NULL;
    int count =0;
    while(A!=NULL){
        count++;
        if(count<m){
            head = A;
            A = A->next;
        }
        ListNode* temp2 = new ListNode();
        temp2->val = A->val;
        temp2->next = A->next;
        A->next = head;
        head = A;
        A = temp2->next;
        free(temp2);
    } 
    return head;
}

int main(){
    ListNode* var1 = new ListNode();
    var1->val = 10;
    ListNode* var2 = new ListNode();
    var2->val = 20;
    ListNode* var3 = new ListNode();
    var3->val = 30;
    ListNode* var4 = new ListNode();
    var4->val = 40;
    ListNode* var5 = new ListNode();
    var5->val = 50;
    ListNode* var6 = new ListNode();
    var6->val = 60;
    var1->next = var2;
    var2->next = var3;
    var3->next = var4;
    var4->next = var5;
    var5->next = var6;
    var6->next = NULL;

    ListNode* head = var1;
    ListNode* rev = reverse(head, 2,5);
    while(rev!=NULL){
        cout<<rev->val<<" ";
        rev = rev->next;
    }

}