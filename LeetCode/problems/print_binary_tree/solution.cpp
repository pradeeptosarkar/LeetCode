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
    
    int calcHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(calcHeight(root->left), calcHeight(root->right)) + 1;
    }
    
    vector<vector<string>> printTree(TreeNode* root) 
    {
        int h=calcHeight(root);
        int c=pow(2,h)-1;
        
        vector<vector<string>> ans (h, vector<string>(c, ""));
        dfs(root, 0, c-1, 0, ans);
        
        return ans;
    }
    
    void dfs(TreeNode* root, int l, int r, int h, vector<vector<string>> &ans)
    {
        if(!root)
            return;
        if(l>r)
            return;
        
        int mid=(l+r)/2;
        
        ans[h][mid]=to_string(root->val);
        dfs(root->left, l, mid-1, h+1, ans);
        dfs(root->right, mid+1, r, h+1, ans);
    }
};