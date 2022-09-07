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
    vector<TreeNode*> ans;
    unordered_map<string,int> mp;
    
    string solve(TreeNode* root)
    {
        if(!root) 
            return "$";
        
        string left = solve(root->left);
        string right = solve(root->right);
        string str = to_string(root->val) +"$"+left+"$"+right;
        
        if(mp[str]==1)
            ans.push_back(root);
        
        mp[str]++;
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        if(!root) 
            return ans;
        
        solve(root);
        return ans;
    }
};