class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if (root==NULL)
        {
            return 0;//base case
        }
        val*=2 ;
        val+=root->val; 
        if(root->left==root->right)
        {
            return val;
        }
        else
        {
            return sumRootToLeaf(root->left,val)+sumRootToLeaf(root->right,val); //DFS Calls
        }
    }
};