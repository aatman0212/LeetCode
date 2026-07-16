class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        while (fastPtr->next && fastPtr->next->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        ListNode* secondHalfHead = slowPtr->next;
        slowPtr->next = nullptr;
        ListNode* previous = nullptr;
        ListNode* current = secondHalfHead;
        while (current) {
            ListNode* nextTemp = current->next;
            current->next = previous;
            previous = current;
            current = nextTemp;
        }
        ListNode* firstHalfCurrent = head;
        ListNode* secondHalfCurrent = previous;
        while (secondHalfCurrent) {
            ListNode* firstHalfNext = firstHalfCurrent->next;
            ListNode* secondHalfNext = secondHalfCurrent->next;
            firstHalfCurrent->next = secondHalfCurrent;
            secondHalfCurrent->next = firstHalfNext;
            firstHalfCurrent = firstHalfNext;
            secondHalfCurrent = secondHalfNext;
        }
    }
};