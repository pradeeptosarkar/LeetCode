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
    void reorderList(ListNode* head) 
    {
        ListNode *slow=head, *fast=head;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *p=NULL, *q=slow, *r=slow->next;
        
        while(q!=NULL)
        {
            r=q->next;
            q->next=p;
            
            p=q;
            q=r;
        }
        
        ListNode *h1=head, *h2=p;
        
        while(h2->next!=NULL)
        {
            ListNode *temp=h1->next;
            h1->next=h2;
            h1=temp;
            
            temp=h2->next;
            h2->next=h1;
            h2=temp;
        }
    }
};
