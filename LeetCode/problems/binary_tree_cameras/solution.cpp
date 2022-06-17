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
    
    int ans;
    
    int minCameraCover(TreeNode* root) 
    {
        ans=0;
        pair<bool,bool> temp=cnt_camera(root);
        if(!temp.second)
            ans++;
        return ans;
    }
    
    pair<bool,bool> cnt_camera(TreeNode* root)
    {
        if(root==NULL)
            return{false, true};
        
        pair<bool,bool> L=cnt_camera(root->left);
        pair<bool,bool> R=cnt_camera(root->right);
        
        bool has_cam=false;
        bool monitored=false;
        
        if(L.first or R.first)
            monitored=true;
        
        if(!L.second or !R.second)
            has_cam=true, monitored=true, ans++;
        
        return {has_cam, monitored};
            
    }
};