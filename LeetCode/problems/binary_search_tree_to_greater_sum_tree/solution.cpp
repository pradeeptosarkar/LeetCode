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
    
    void helper(TreeNode* root, int &maxi)
    {
        if(!root)
            return;
        
        helper(root->right, maxi);
        
        root->val+=maxi;
        maxi=root->val;
        
        helper(root->left, maxi);
            
    }
    
    TreeNode* bstToGst(TreeNode* root) 
    {
        int maxi=0;
        helper(root, maxi);        
        return root;
    }
};