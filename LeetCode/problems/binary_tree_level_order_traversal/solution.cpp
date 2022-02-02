class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderNodes;
        if(!root)
            return levelOrderNodes;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            vector<int> levelNodes;
            for(int i=0;i<s;i++)
            {
                TreeNode* n=q.front();
                if(n)
                    levelNodes.push_back(n->val);
                q.pop();
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            levelOrderNodes.push_back(levelNodes);
        }
        return levelOrderNodes;
    }
};