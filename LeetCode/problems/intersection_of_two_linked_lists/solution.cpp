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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* node1=headA;
        ListNode* node2=headB;
        
        while(node1!=node2)
        {
            node1 = node1==NULL ? headB : node1->next;
            node2 = node2==NULL ? headA : node2->next;
        }
        
        return node1;        
    }
};