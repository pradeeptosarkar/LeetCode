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
    bool isBST(TreeNode *root, long long lower, long long upper)
    {
        if(!root)
            return 1;
        if(root->val<=lower)
            return 0;
        if(root->val>=upper)
            return 0;
        return isBST(root->left,lower,root->val)&&isBST(root->right,root->val,upper);
        
    }
    
    bool isValidBST(TreeNode* root) 
    {
        if(root==0)
            return 1;
        if((!root->left) && (!root->right))
            return 1;
        return isBST(root,-2147483649,2147483649);
    }
};