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
        
        vector<int> tp;
        int temp,ans=0;
        
        while(head!=NULL)
        {
            temp=head->val;
            tp.push_back(temp);
            head=head->next;
        }
        int n=tp.size();
        
        for(int i=0;i<n;i++)
            ans+=(tp[i]*pow(2,n-1-i));
        
        return ans;
        
    }
};