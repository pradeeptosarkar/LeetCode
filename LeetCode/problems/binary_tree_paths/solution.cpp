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
    
    void solve(TreeNode* root,vector<string>&s,string ans){
        if(root==NULL){
           
            return;
        }
        
        // ans+=to_string(root->val);
        // ans+="->";
        if(root->left==NULL && root->right==NULL){
             ans+=to_string(root->val);
            s.push_back(ans);
            return ;
        }
        
       
        
        solve(root->left,s,ans+to_string(root->val)+"->");
        
        solve(root->right,s,ans+to_string(root->val)+"->");
         
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>s;
        string ans="";
        solve(root,s,ans);
        return s;
    }
};