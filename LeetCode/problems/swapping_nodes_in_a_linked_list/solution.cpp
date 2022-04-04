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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* fast=head;
        ListNode* prev=head;
        for(int i=0;i<k;i++)
        {
            if(fast==NULL)
                return head;
            prev=fast;
            fast=fast->next;
        }
        ListNode* first=prev;
        ListNode* slow=head;
        while(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        swap(first->val,slow->val);
        return head;
    }
};