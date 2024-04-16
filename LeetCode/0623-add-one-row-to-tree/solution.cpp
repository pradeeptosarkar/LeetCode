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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth==1)
        {
            TreeNode* newRoot = new  TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        
        while(!q.empty())
        {
            level++;
            
            if(level==depth)
                break;
            
            int size=q.size();
            
            while(size--)
            {
                TreeNode* tempNode = q.front();
                
                if(tempNode->left)
                    q.push(tempNode->left);
                if(tempNode->right)
                    q.push(tempNode->right);
                
                q.pop();
            }
        }
        
        int size=q.size();
        
        while(size--)
        {
            TreeNode* temp=q.front();
            TreeNode *tempLeft= new TreeNode(val), *tempRight= new TreeNode(val);
            tempLeft->left = temp->left;
            temp->left = tempLeft;
            tempRight->right = temp->right;
            temp->right = tempRight;
            q.pop();
            
        }
        return root;
        
    }
};
