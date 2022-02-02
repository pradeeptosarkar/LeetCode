/* PSRC CP Template 3 */

class Solution {
public:
    vector<int> vec;
    bool isValidBST(TreeNode* root) {
        
        inorder(root);
        if (std::is_sorted(vec.begin(), vec.end())) {
            for (int i=0; i<(vec.size()-1); i++)
            {
                if (vec[i] == vec[i+1])
                    return false;
            }
            return true;
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