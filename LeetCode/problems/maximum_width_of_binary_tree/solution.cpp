//::Pradeepto Sarkar LC662 27/02/2022:://

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root)
            return 0;
        
        int ans=INT_MIN;
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            int n=q.size();
            int start=q.front().second;
            int end=q.back().second;
            ans=max(ans, end-start+1);
            
            while(n--)
            {
                auto p=q.front();
                unsigned id=p.second-start;
                q.pop();
                
                if(p.first->left)
                    q.push({p.first->left, 2*id+1});
                    
                if(p.first->right)
                    q.push({p.first->right, 2*id+2});
            }
        }
        
        return ans;
    }
};