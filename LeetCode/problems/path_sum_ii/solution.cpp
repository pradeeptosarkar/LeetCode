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
    
    vector<vector<int>> ans;
    vector<int> currPath;
    
    void dfs(TreeNode* root, int tempSum, int targetSum)
    {
        if(!root)
            return;
        
        currPath.push_back(root->val);
        tempSum+=root->val;
        
        if(tempSum==targetSum and !root->left and !root->right)
            ans.push_back(currPath);
        
        dfs(root->left, tempSum, targetSum);
        dfs(root->right, tempSum, targetSum);
        
        currPath.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        dfs(root, 0, targetSum);
            return ans;
        
    }
};