class Solution {
public:
    long long max_product=0;
    void ans(TreeNode* root,int total)
    {
        if(!root)
        return;
        max_product=max(max_product,(long long)(root->val)*(total-root->val));
        ans(root->left,total);
        ans(root->right,total);
    }
    long long helper(TreeNode* root)
    {
        if(!root)
            return 0;
        root->val=root->val+helper(root->right)+helper(root->left);
        return root->val;
    }
    int maxProduct(TreeNode* root) {
        long long total=helper(root);
        ans(root,total);
        return max_product%1000000007;
    }
};