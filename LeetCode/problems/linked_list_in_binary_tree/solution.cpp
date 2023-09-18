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
    
    bool help(ListNode* head, TreeNode* root)
    {
        if(!head) return true;
        if(!root) return false;
        
        if(head->val==root->val)
            return help(head->next , root->left ) || help(head->next , root->right );
        else
            return false ;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if(!head) return true;
        if(!root) return false;
        
        bool right,left;
        bool ans=false;
        
        if(head->val==root->val)
        {
            ans |= help(head,root);
            
            //right=isSubPath(head->next,root->right);
            //left=isSubPath(head->next,root->left);
            
            //return left or right;
        }
        
        //else
        //{
            //right=isSubPath(head,root->right);
            //left=isSubPath(head,root->left);
            
            //return left or right;
        //}
        
        ans|= isSubPath(head, root->left) or isSubPath(head, root->right);
        return ans;
        
        //return right or left;
    }
};