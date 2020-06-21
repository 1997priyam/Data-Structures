#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// Using the fast and slow pointer method to detect cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *sp = head, *fp = head;
        while(fp!=NULL) {
            if (fp->next == NULL) break;
            sp = sp->next;
            fp = fp->next->next;
            if(sp == fp) return true;
        }
        return false;
    }
};