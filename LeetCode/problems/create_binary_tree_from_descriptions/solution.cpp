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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*> hashmap;
        unordered_set<int> isaChild;
        unordered_set<int> nodes;   
        
        for(auto i:descriptions)
        {
            if(hashmap.find(i[0])==hashmap.end())
                hashmap[i[0]] = new TreeNode(i[0]);
            
            if(hashmap.find(i[1])==hashmap.end())
                hashmap[i[1]] = new TreeNode(i[1]);
            
            if(i[2])
                hashmap[i[0]]->left=hashmap[i[1]];
            else
                hashmap[i[0]]->right=hashmap[i[1]];
            
            nodes.insert(i[0]);
            isaChild.insert(i[1]);
            
            if(isaChild.find(i[0])!=isaChild.end())
                nodes.erase(i[0]);
        }
        
        for(auto n:nodes)
            if(isaChild.find(n)==isaChild.end())
                return hashmap[n];
        
        return nullptr;
    }
};