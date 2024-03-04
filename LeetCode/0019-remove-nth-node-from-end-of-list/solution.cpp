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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* root = new ListNode();
        root->next=head;
        ListNode* a = root;
        ListNode* b = root;
        
        for(int i=0;i<n;i++)
            a=a->next;
        
        while(a->next)
        {
            a=a->next;
            b=b->next;
        }
        
        b->next=b->next->next;
        return root->next;
    }
};
