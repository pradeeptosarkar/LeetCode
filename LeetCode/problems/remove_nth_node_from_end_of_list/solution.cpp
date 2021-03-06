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
     
        if(head->next==nullptr)
            return nullptr;
        ListNode* temp=head;
        ListNode* it=head;
        
        long long count=0;
        
        while(it!=nullptr)
        {
            count++;
            it=it->next;
        }        
        if(n==count)
        {
            head=head->next;
            return head;
        }
        count-=n;
        
        while(temp!=nullptr)
        {
            if(count==1)
            {
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
            count--;
        }
        return head;
    }
};