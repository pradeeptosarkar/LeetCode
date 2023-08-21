/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int calcLength(ListNode *head)
    {
        int length = 0;
    
        while(head != NULL) 
        {
            ++length;
            head = head->next;
        }
    
        return length;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL or head->next==NULL)
            return head;
        
        int n=calcLength(head);
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode *curr, *nex;
        
        while(n>=k)
        {
            curr=prev->next;
            nex=curr->next;
            
            for(int i=0;i<k-1;i++)
            {
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            n-=k;
        }
        
        return dummy->next;
    }
};