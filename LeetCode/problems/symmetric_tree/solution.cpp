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
    
    bool solve(TreeNode* left, TreeNode* right)
    {
        if(left==NULL or right==NULL)
            return left==right;
        
        if(left->val!=right->val)
            return false;
        
        return solve(left->left,right->right) and solve(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        if(!root or (!root->left and !root->right))
            return true;
        
        return solve(root->left, root->right);
    }
};