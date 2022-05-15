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
    int deepestLeavesSum(TreeNode* root) 
    {
        if(root->left==NULL and root->right==NULL)
            return root->val;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        int last_sum=0;
        
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            
            if(node==NULL)
            {
                if(q.size()==0)
                {
                    last_sum=sum;
                    break;
                }
                q.push(NULL);
                sum=0;
            }
            
            else
            {
                sum+=node->val;
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
        }
        return last_sum;
        
    }
};