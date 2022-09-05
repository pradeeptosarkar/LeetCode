/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans={};
        queue<Node*> q;
        
        if(root)
            q.push(root);
        
        while(!q.empty())
        {
            vector<int> temp;
            int s=q.size();
            while(s--)
            {
                temp.push_back(q.front()->val);
                Node* tt=q.front();
                q.pop();
                
                for(auto i:tt->children)
                    q.push(i);
                
            }
            ans.push_back(temp);
        }
        return ans;
    }
};