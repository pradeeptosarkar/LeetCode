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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL or head->next==NULL or k==0)
            return head;
        
        ListNode* first=head;
        
        int n=1;
        
        while(first->next!=NULL)
        {
            n+=1;
            first=first->next;
        }
        
        first->next=head;
        ListNode *newHead;
        
        k%=n;
        n-=k;
        
        while(n--)
            first=first->next;
        
        newHead=first->next;
        first->next=NULL;
        
        return newHead;
    }
};