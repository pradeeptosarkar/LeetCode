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
class Solution 
{
public:
    
    vector<vector<int>> dfs(vector<vector<int>>& answerVector, TreeNode* root, int level)
    {
        if(!root)
            return answerVector;
        
        if(level==answerVector.size())
            answerVector.push_back({});
        
        answerVector[level].push_back(root->val);
        dfs(answerVector, root->left, level+1);
        dfs(answerVector, root->right, level+1);
        
        return answerVector;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> answerVector;
        return dfs(answerVector, root, 0);
        
       
    }
};