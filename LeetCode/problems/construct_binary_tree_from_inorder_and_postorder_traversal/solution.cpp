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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        
        TreeNode* root=buildNewTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
        
        return root;
    }
    
    TreeNode* buildNewTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int,int> &mp)
    {
        if(postStart>postEnd or inStart>inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot=mp[root->val];
        int leftNums=inRoot-inStart;
        
        root->left= buildNewTree(inorder, inStart, inRoot-1, postorder, postStart, postStart+leftNums-1, mp);
        root->right= buildNewTree(inorder, inRoot+1, inEnd, postorder, postStart+leftNums, postEnd-1, mp);
        
        return root;
    }
};