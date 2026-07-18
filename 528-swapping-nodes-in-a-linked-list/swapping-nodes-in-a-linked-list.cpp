class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int val1=0,val2=0,n=0;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            n++;
            if(n==k){
                val1=temp->val;
                break;
            }
            temp=temp->next;
        }
        temp=head;
        count=count-k+1;
        while(count!=1){
            temp=temp->next;
            count--;
        }
        val2=temp->val;
        temp->val=val1;
        temp=head;
        while(k!=1 && temp->next!=nullptr){
            temp=temp->next;
            k--;
        }
        temp->val=val2;
        return head;
    }
};