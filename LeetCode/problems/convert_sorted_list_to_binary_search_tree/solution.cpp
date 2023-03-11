class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(!head)
            return NULL;
        if(!head->next)
            return new TreeNode(head->val);
        
        ListNode *slow=head, *fast=head, *temp=head;
        
        while(fast and fast->next)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        temp->next=NULL;
        
        TreeNode* root = new TreeNode(slow->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        
        return root;
    }
};