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
    
    string ans;
    
    void solve(TreeNode* root, string curr)
    {
        if(!root)
            return;
        
        curr=char(root->val+'a')+curr;
        
        if(!root->left and !root->right)
            if(ans=="" or ans>curr)
                ans=curr;
        
        if(root->left)
            solve(root->left, curr);
        if(root->right)
            solve(root->right, curr);
    }
    
    string smallestFromLeaf(TreeNode* root) 
    {
        solve(root, "");
        return ans;
    }
};
