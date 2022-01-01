class Solution {
    TreeNode* BalanceSearchTree(int start,int end,vector<int>& nums)
    {
        if(start == end)
            return new TreeNode(nums[end]);
        if(start > end)
            return NULL;
        int mid = start + (end - start)/2;
        TreeNode* pnt = new TreeNode(nums[mid]);
        pnt -> left =  BalanceSearchTree(start,mid-1,nums);
        pnt -> right =  BalanceSearchTree(mid+1,end,nums);
        return pnt;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return BalanceSearchTree(0,n-1,nums);
        
    }
};