class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
         ListNode *slow = head, *fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != NULL){
            //the length of list is odd
            //in this situation we should ignore the middle node
            slow = slow->next;
        }
        
        //slow: later part of original list
        //fast: former part of original list
        slow = reverse(slow);
        fast = head;
        
        while(slow != NULL){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head){
        //reverse the later part of original list
        ListNode* prev = NULL;
        ListNode* tmp;
        while(head != NULL){
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        //when the loop finishes, head is NULL, 
        //and prev is the last node in the original list
        return prev;
    }
};