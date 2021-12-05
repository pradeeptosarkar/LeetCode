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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        
        if(!root)
            return ans;
        
        
        stack<TreeNode*> stk;
        
        stk.push(root);
        
        TreeNode* cur;
        
        while(!stk.empty())
        {
            cur=stk.top();
            stk.pop();
            
            ans.emplace_back(cur->val);
            
            if(cur->right)
                stk.push(cur->right);
            
            if(cur->left)
                stk.push(cur->left);
        }
        
        return ans;
    }
};