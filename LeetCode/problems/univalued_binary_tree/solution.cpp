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
    bool isUnivalTree(TreeNode* root) {
       if(!root)
            return true;
        bool fleft=0,fright=0;
        if(root->left)
            if(root->left->val!=root->val)
                fleft=1;
        if(root->right)
            if(root->right->val!=root->val)
                fright=1;
        if(fleft||fright)
            return false;
        return isUnivalTree(root->left)&&isUnivalTree(root->right); 
    }
};