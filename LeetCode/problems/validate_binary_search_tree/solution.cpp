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
    vector<int> vec;
    bool isValidBST(TreeNode* root) {
        
        inorder(root); // BST inorder traversal should return sorted array
        if (std::is_sorted(vec.begin(), vec.end())) {
            for (int i=0; i<(vec.size()-1); i++)
            {
                if (vec[i] == vec[i+1]) // if 2 elements same, cannot be BST. Return false
                    return false;
            }
            return true; // the largest element would be the last one
        }
        else {
            return false; 
        }
     
    }
    void inorder(TreeNode *node)
    {
        if (node==NULL)
            return;
        
        if (node->left)
            inorder(node->left);
        
        vec.push_back(node->val);
        
        if (node->right)
            inorder(node->right);
    }
    
};