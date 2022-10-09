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
    
    set<int> s;
    
    bool findTarget(TreeNode* root, int k) 
    {
        if(root==NULL)
            return false;
        if(s.count(k-root->val))
            return 1;
        s.insert(root->val);
        
        return findTarget(root->left,k) or findTarget(root->right,k);
        
    }
};