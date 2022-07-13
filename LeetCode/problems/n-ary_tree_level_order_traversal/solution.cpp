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

class Solution 
{
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> answerVector;
        
        if(!root)
            return answerVector;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> currLevel;
            
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                Node* n=q.front();
                currLevel.push_back(n->val);
                q.pop();
                
                vector<Node*> temp=n->children;
                for(int j=0;j<temp.size();j++)
                    q.push(temp[j]);
            }
            answerVector.push_back(currLevel);
        }
        return answerVector;
        
    }
};