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
 *
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        
    }
};*/
 
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

bool done;

void helper(TreeNode* &root, int &val){

    

    // If val already inserted to its correct place then do nothing

    if(done)

        return;

    

    // If val is greater than the root's value then insert a node with val as its value above the root

    if(val>root->val){

        TreeNode *x=new TreeNode(val);

        x->left=root;

        root=x;

        done=true;

        return;

    }

               

    // If root's right node is NULL simply make the root's right node a node with value as val

    if(!root->right){

        root->right=new TreeNode(val);

        done=true;

        return;

    }

    

    // Recursively call on the right part of the root

    helper(root->right, val);

}

TreeNode* insertIntoMaxTree(TreeNode* root, int val) {

    done=false;

    

    helper(root, val);

    

    return root;

}

};