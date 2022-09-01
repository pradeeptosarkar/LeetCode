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
    
    void dfs(TreeNode* node, int temp)
    {
        if(!node)
            return;
        
        if(node->val>=temp)
            ans++;
        
        dfs(node->left, max(temp,node->val));
        dfs(node->right, max(temp,node->val));
    }
    
    int goodNodes(TreeNode* root) 
    {
        dfs(root, INT_MIN);
        return ans;
    }
};