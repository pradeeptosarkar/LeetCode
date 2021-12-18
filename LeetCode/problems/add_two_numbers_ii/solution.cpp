class Solution {
public:
    
    int size(ListNode* temp){
        int sz = 0;
        while(temp != NULL) sz++, temp = temp->next;
        return sz;
    }
    
    void addLast(ListNode* head, int data){
        ListNode* temp = new ListNode(data, NULL), *tail = head;
        while(tail->next != NULL)
            tail = tail->next;
        
        if(head == NULL)
            head = temp;
        else{
            tail->next = temp;
            head = temp;
        }
    }
    
    int helper(ListNode* l1, int pv1, ListNode* l2, int pv2, ListNode* res){
        if(l1 == NULL && l2 == NULL)
        return 0;

        int data = 0;
        if(pv1 > pv2){
            int oc = helper(l1->next, pv1-1, l2, pv2, res);
            data = l1->val + oc;
        } else if(pv1 < pv2){
            int oc = helper(l1, pv1, l2->next, pv2-1, res);
            data = l2->val + oc;
        } else{
            int oc = helper(l1->next, pv1-1, l2->next, pv2-1, res);
            data = l1->val + l2->val + oc;
        }

        int digit = data % 10;
        int carry = data / 10;

        addLast(res, digit);
        return carry;

    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL, *curr = head;

        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        int oc = helper(l1, size(l1), l2, size(l2), res);
        if(oc > 0)
        addLast(res, oc);
        
        res = res->next;
        return reverseList(res);
    }
};