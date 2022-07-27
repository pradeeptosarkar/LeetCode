/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) 
{
    if(!root)
        return;
    
    if(!root.left && !root.right)
        return;
    
    const L=root.left;
    const R=root.right;
    
    flatten(L);
    flatten(R);
    
    root.left=null;
    
    if(L)
        {
            root.right=L;
            let backup=L;
            let temp=L;
            
            while(temp)
                {
                    backup=temp;
                    temp=temp.right;
                }
            
            backup.right=R;
        }
    return;
    
};