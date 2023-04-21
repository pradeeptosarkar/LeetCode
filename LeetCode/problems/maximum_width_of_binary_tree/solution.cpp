class Solution 
{
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        
        int ans=0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            int levelSize=q.size();
            int start=q.front().second;
            int end=q.back().second;
            
            ans=max(ans, end-start+1);
            
            for(int i=0;i<levelSize;i++)
            {
                TreeNode* tempNode=q.front().first;
                int nodeIndex=q.front().second;
                q.pop();
                
                if(tempNode->left!=NULL)
                    q.push({tempNode->left, (long long)2*nodeIndex+1});
                if(tempNode->right!=NULL)
                    q.push({tempNode->right, (long long)2*nodeIndex+2});  
            }
        }
        return ans;
    }
};  
