#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *sp = head, *fp = head;
        while(fp != NULL) {
            if(fp->next == NULL) break;
            sp = sp->next;
            fp = fp->next->next;
        }
        ListNode *newList = reverseList(sp);
        while(head != sp) {
            if(head->val != newList->val) {
                return false;
            }
            head = head->next;
            newList = newList->next;
        }
        return true;
        
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *initial = NULL, *nextPtr;
        while(head != NULL) {
            nextPtr = head->next;
            head->next = initial;
            initial = head;
            head = nextPtr;
        }
        return initial;
    }
};