/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *firstPointer=head, *secondPointer=head, *prevNode=NULL;
        
        for(int i=0; i<n-1; i++){
            secondPointer = secondPointer->next;
        }
        while(secondPointer->next!=NULL){
            prevNode = firstPointer;
            firstPointer = firstPointer->next;
            secondPointer = secondPointer->next;
        }
        if(prevNode){
            prevNode->next = firstPointer->next;
        }
        else{
            head = firstPointer->next;
        }
        delete(firstPointer);
        return head;
    }
};