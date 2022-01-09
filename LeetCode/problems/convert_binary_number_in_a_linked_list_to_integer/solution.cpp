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
    int getDecimalValue(ListNode* head) 
    {
        vector<int> bin;
        int temp,ans=0;
        
        while(head!=NULL)
        {
            temp=head->val;
            bin.push_back(temp);
            head=head->next;
        }
        int n=bin.size();
        
        for(int i=0;i<n;i++)
            ans+=(bin[i]*(pow(2,n-1-i)));
        
        return ans;
    }
};