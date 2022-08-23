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
    
    int pairSum(ListNode* head) 
    {
        ListNode *slow=head, *fast=head;
        int ans=INT_MIN;
        
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
            int temp=fast->val+slow->val;
            ans=max(ans,temp);
            slow=slow->next;
            fast=fast->next;
        }
        
        return ans;    
    }
    
};