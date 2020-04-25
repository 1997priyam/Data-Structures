
/*

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

*/


#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;
        if(k == 0) return head;
        
        ListNode *first = head;
        ListNode *temp = head;
        ListNode *last = head;
        int count = 0;
        while(temp != NULL){
            count++;
            last = temp;
            temp = temp->next;
        }
        int cutPoint = count - (k%count);
        if (cutPoint == count) return first;
        temp = first;
        for(int i=0; i<cutPoint-1; i++) {
            temp = temp->next;
        }
        ListNode *ans = temp->next;
        temp->next = NULL;
        last->next = first;
        return ans;
        
    }
};