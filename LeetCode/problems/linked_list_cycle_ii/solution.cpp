/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head)
            return NULL;
        
        ListNode *fast=head, *slow=head, *temp=head;
        
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow)
            {
                while(slow!=temp)
                {
                    slow=slow->next;
                    temp=temp->next;
                }
                
                return slow;
            }
        }
        
        return NULL;
    }
};