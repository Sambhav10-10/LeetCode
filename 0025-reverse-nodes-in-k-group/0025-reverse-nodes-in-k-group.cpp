class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevGroupEnd = &dummy, *curr = head, *next = nullptr;

        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        while (count >= k) {
            curr = prevGroupEnd->next;
            next = curr->next;
            for (int i = 1; i < k; ++i) {
                curr->next = next->next;
                next->next = prevGroupEnd->next;
                prevGroupEnd->next = next;
                next = curr->next;
            }
            prevGroupEnd = curr;
            count -= k;
        }
        return dummy.next;
    }
};
