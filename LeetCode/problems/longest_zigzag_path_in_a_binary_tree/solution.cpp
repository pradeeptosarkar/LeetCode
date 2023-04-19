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
    int ans=0;
    
    void dfs(TreeNode* root, int len, bool goLeft)
    {
        if(root==NULL)
            return;
        
        ans=max(ans, len);
        
        if(goLeft)
        {
            dfs(root->left, len+1, false);
            dfs(root->right, 1, true);
        }
        
        else
        {
            dfs(root->left, 1, false);
            dfs(root->right, len+1, true);
        }
    }
    
    int longestZigZag(TreeNode* root) 
    {
        dfs(root, 0, true);
        dfs(root, 0, false);
        return ans;
        
    }
};