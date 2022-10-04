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
    //dfs implementation
    
    void help(TreeNode* left, TreeNode* right, bool isOdd)
    {
        if(!left or !right)
            return;
        
        if(isOdd)
        {
            int temp=left->val;
            left->val=right->val;
            right->val=temp;
        }
        
        help(left->left, right->right, !isOdd);
        help(left->right, right->left, !isOdd);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        help(root->left, root->right, 1);
        return root;        
    }
};