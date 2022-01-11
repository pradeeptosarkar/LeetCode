class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
       vector<int> res=inorderTraversal(root);
        int l=0;
        int h=res.size()-1;
        while(h>l)
        {   if(res[l]+res[h]==k) return true;
            else if(res[l]+res[h]>k) h--;
            else l++;
        }
        return false;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        TreeNode * cur=root;
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                in.emplace_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode * prev=cur->left;
                while(prev->right&&prev->right!=cur)
                      prev=prev->right;
                if(prev->right==NULL)
                { prev->right=cur;
                  cur=cur->left; 
                }
                else
                {
                    prev->right=NULL;
                    in.emplace_back(cur->val);
                    cur=cur->right;
                        
                }
                
            }
        }
        return in;
    }
};