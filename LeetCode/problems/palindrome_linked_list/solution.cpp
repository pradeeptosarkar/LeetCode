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
    
    ListNode *reverseList(ListNode* curr)
    {
        ListNode* pre=NULL;
        ListNode* nex=NULL;
        
        while(curr!=NULL)
        {
            nex=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nex;
        }
        
        return pre;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL or head->next==NULL)
            return true;
        
        ListNode *fast=head;
        ListNode *slow=head;
        
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        slow->next = reverseList(slow->next);
        slow=slow->next;
        ListNode *newNode=head;
        
        while(slow!=NULL)
        {
            if(newNode->val!=slow->val)
                return false;
            
            slow=slow->next;
            newNode=newNode->next;
        }
        
        return true;
    }
};