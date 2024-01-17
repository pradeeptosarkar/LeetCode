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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        
        TreeNode* root=buildNewTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        
        return root;
    }
    
    TreeNode* buildNewTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int,int> &mp)
    {
        if(preStart>preEnd or inStart>inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot=mp[root->val];
        int leftNums=inRoot-inStart;
        
        root->left= buildNewTree(preorder, preStart+1, preStart+leftNums, inorder, inStart, inRoot-1, mp);
        root->right= buildNewTree(preorder, preStart+leftNums+1, preEnd, inorder, inRoot+1, inEnd, mp);
        
        return root;
    }
};