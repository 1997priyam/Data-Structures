
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *temp = head, *secondList = NULL, *prev = NULL, *temp2 = NULL;
        int count = 1;
        while(temp != NULL) {
            if(count % 2 == 0) {
                if(secondList == NULL) {
                    secondList = temp2 = temp;
                } else {
                    temp2->next = temp;
                    temp2 = temp;
                }
            } else {
                if(prev != NULL) {
                    prev->next = temp;
                }
                prev = temp;
            }
            temp = temp->next;
            count++;
        }
        prev->next = secondList;
        if(temp2 != NULL) temp2->next = NULL;
        return head;
    }
};