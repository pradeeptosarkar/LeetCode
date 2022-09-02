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
    
    pair<int, TreeNode*> dfs(TreeNode* root) 
    {
        if (!root) 
            return {0, NULL};
        
        pair<int, TreeNode*> l=dfs(root->left), r=dfs(root->right);

        int a=l.first, b=r.first;
        
        return {max(a, b)+1, a==b ? root : a>b ? l.second : r.second};
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        return dfs(root).second;        
    }
};