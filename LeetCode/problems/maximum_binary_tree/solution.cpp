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
    int i;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int maxi=INT_MIN;
        if(nums.size()==0)
            return NULL;
        for(i=0;i<nums.size();i++)
        {
            maxi=max(maxi, nums[i]);
        }
       
        for(i=0;i<nums.size();i++)
            if(nums[i]==maxi)
                break;
        
        TreeNode *res= new TreeNode(maxi);
        vector<int> l(nums.begin(),nums.begin()+i);
        vector<int> r(nums.begin()+i+1, nums.end());
        res->left= constructMaximumBinaryTree(l);
        res->right = constructMaximumBinaryTree(r);
       return res;
    }
};