class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallHead = nullptr, *smallTail = nullptr;
        ListNode *largeHead = nullptr, *largeTail = nullptr;

        ListNode* temp = head;

        while (temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = nullptr;

            if (temp->val < x) {
                if (smallHead == nullptr) {
                    smallHead = temp;
                    smallTail = temp;
                } else {
                    smallTail->next = temp;
                    smallTail = temp;
                }
            } else {
                if (largeHead == nullptr) {
                    largeHead = temp;
                    largeTail = temp;
                } else {
                    largeTail->next = temp;
                    largeTail = temp;
                }
            }

            temp = next;
        }

        if (smallHead == nullptr)
            return largeHead;

        smallTail->next = largeHead;

        return smallHead;
    }
};