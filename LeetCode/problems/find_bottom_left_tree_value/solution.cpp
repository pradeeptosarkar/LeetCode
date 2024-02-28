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
    int findBottomLeftValue(TreeNode* root) 
    {
        int ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size())
        {
            int size=q.size();
            TreeNode* frontt=q.front();
            ans=frontt->val;
            
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
        return ans;
    }
};