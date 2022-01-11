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
     int prev=-1;
        int max = INT_MAX;
        void inorder(TreeNode* root){
        if(!root)
            return ;
     
        inorder(root->left);
            
            if(prev==-1)
                ;
            else if(root->val-prev<max)
                max = root->val-prev;
            
         prev = root->val;
        inorder(root->right);

    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        
        return max;
    }
};