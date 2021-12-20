class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while(fast && fast->next){
            if(prev != NULL)
                prev = prev->next;
            if(prev == NULL)
                prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;
        return head;
    }
};