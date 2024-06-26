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
    
    void solve(TreeNode* root, int& ans, int tempSum)
    {
        if(root->left==NULL and root->right==NULL)
        {
            tempSum=tempSum*10+root->val;
            ans+=tempSum;
            return;
        }
        
        tempSum=tempSum*10+root->val;
        
        if(root->left)
            solve(root->left,ans,tempSum);
        if(root->right)
            solve(root->right,ans,tempSum);
    }
    
    int sumNumbers(TreeNode* root) 
    {
        int ans=0, tempSum=0;
        solve(root, ans, tempSum);
        return ans;
    }
};
