/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
    }
};*/

class Solution {

private:

    unordered_map<TreeNode*,TreeNode*>parents;

    void getParents(TreeNode* root){

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){

            auto cur=q.front(); q.pop();

            if(cur->left){

                q.push(cur->left);

                parents[cur->left]=cur;

            }

            if(cur->right){

                q.push(cur->right);

                parents[cur->right]=cur;

            }

        }

    }

public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        getParents(root);

        unordered_set<TreeNode*>visited;

        queue<TreeNode*>q;

        q.push(target);

        visited.insert(target);

        int dis=0;

        while(!q.empty()){

            int size=q.size();

            if(dis==k) break;

            dis++;

            for(int i=0;i<size;i++){

                auto cur=q.front(); q.pop();

                if(parents[cur] && !visited.count(parents[cur])){

                    q.push(parents[cur]);

                    visited.insert(parents[cur]);

                }

                if(cur->left && !visited.count(cur->left)){

                    q.push(cur->left);

                    visited.insert(cur->left);

                }

                if(cur->right && !visited.count(cur->right)){

                    q.push(cur->right);

                    visited.insert(cur->right);

                }

            }

        }

        vector<int>ans;

        while(!q.empty()){

            auto cur = q.front(); q.pop();

            ans.push_back(cur->val);

        }

        return ans;    

    }

};