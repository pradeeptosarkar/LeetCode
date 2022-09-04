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
    
    map<int, map<int, multiset<int>>> mp;
    
    void dfs(TreeNode* node, int x, int y)
    {
        if(node)
        {
            mp[x][y].insert(node->val);
            dfs(node->left, x-1, y+1);
            dfs(node->right, x+1, y+1);
        }
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans={};
        
        dfs(root,0,0);
        
        for(auto i=mp.begin(); i!=mp.end(); i++)
        {
            ans.push_back(vector<int>());
            
            for(auto j=i->second.begin(); j!=i->second.end(); j++)
                ans.back().insert(end(ans.back()), j->second.begin(), j->second.end());
        }
        
        return ans;
    }
};