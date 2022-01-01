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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
       if(head==NULL) return NULL;
    if(head->next==NULL) return new TreeNode(head->val);
    
    ListNode* s=head,*f=head,*pre=NULL;
    while(f!=NULL && f->next!=NULL){
        f=f->next->next;
        pre=s;
        s=s->next;
    }
    TreeNode* root=new TreeNode(s->val);
    pre->next=NULL;
    root->left=sortedListToBST(head);
    root->right=sortedListToBST(s->next);
    
    return root; 
    }
};