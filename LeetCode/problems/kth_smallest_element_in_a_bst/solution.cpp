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
    int solve(TreeNode *root,vector<int>& v,int k){
    if(root==NULL){
        return -1;
    }
    solve(root->left,v,k);
    v.push_back(root->val);          
    solve(root->right,v,k);

    if (v.size() >= k) {
            return v[k - 1];     
        }
        return -1;
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        return solve(root,v,k);
    }
};