class Solution {
public:
    
    ListNode * reverse(ListNode *head)
    {
        ListNode *prev=NULL;
        ListNode *temp;
        
        while(head!=NULL)
        {
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode *slow=head, *fast=head;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast!=NULL)
            slow=slow->next;
        
        slow=reverse(slow);
        fast=head;
        
        while(slow!=NULL)
        {
            if(slow->val!=fast->val)
                return false;
            fast=fast->next;
            slow=slow->next;
        }
        
        return true;    
    }
    
};