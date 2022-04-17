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
    
    TreeNode *head = new TreeNode();
    TreeNode *curr = head;
    
    void left_inOrder(TreeNode *root)
    {
        if(!root)
            return;
        
        left_inOrder(root->left);
            
        curr->right=root;
        curr=root;
        curr->left=nullptr;
        
        left_inOrder(root->right);
            
    }
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        left_inOrder(root);
        return head->right;        
    }
};