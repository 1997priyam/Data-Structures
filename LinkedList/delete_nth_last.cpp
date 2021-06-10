
//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1, *ptr2, *prev;
        ptr1 = ptr2 = prev= head;
        while(n>0 && ptr1 != NULL) {
            ptr1 = ptr1->next;
            n--;
        }
        while(ptr1 != NULL) {
            prev = ptr2;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        if(prev == ptr2) head = ptr2->next;
        else prev->next = ptr2->next;
        delete ptr2;
        return head;
    } 
};