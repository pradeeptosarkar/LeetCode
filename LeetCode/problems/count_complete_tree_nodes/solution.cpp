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
    int countNodes(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int l=left(root);
        int r=right(root);
        
        if(l==r)
            return (1<<l)-1;
        return 1+countNodes(root->left)+countNodes(root->right);        
    }
    
    int left(TreeNode* root)
    {
        int ans=0;
        while(root)
        {
            ans++;
            root=root->left;
        }
        return ans;
    }
    
    int right(TreeNode* root)
    {
        int ans=0;
        while(root)
        {
            ans++;
            root=root->right;
        }
        return ans;
    }
};