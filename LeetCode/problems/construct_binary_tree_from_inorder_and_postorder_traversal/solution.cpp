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
    
    TreeNode* solve(vector<int>& inorder, int a, int b, vector<int>& postorder, int c, int d)
    {
        if(a>b or c>d)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[d]);
        
        int partitionIndex=0;
        
        while(root->val!=inorder[partitionIndex])
        {
            partitionIndex++;
        }
        
        root->left=solve(inorder,a,partitionIndex-1,postorder,c,c+partitionIndex-a-1);
        root->right=solve(inorder,partitionIndex+1,b,postorder,c+partitionIndex-a,d-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);        
    }
};