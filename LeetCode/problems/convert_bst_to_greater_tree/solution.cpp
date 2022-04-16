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
    
    void helper(TreeNode* root, int &greaterSum)
    {
        if(!root)
            return;
        helper(root->right, greaterSum);
        
        root->val+=greaterSum;
        greaterSum=root->val;
        
        helper(root->left, greaterSum);
        
    }
    
    TreeNode* convertBST(TreeNode* root) 
    {
        int greaterSum=0;
        helper(root, greaterSum);
        return root;       
        
    }
};