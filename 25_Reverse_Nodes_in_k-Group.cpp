
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            if (kth == NULL) {
                break;
            }

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            ListNode* groupStart = curr;

            while (curr != groupNext) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            groupPrev->next = kth;
            groupPrev = groupStart;
        }

        return dummy->next;
    }
};
