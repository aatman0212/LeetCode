class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointerA = headA;
        ListNode* pointerB = headB;
        while (pointerA != pointerB) {
            pointerA = (pointerA != nullptr) ? pointerA->next : headB;
            pointerB = (pointerB != nullptr) ? pointerB->next : headA;
        }
        return pointerA;
    }
};