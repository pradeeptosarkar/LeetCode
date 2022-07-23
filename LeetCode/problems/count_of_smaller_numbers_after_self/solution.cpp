class BITree
{
public:
    vector<int> tree;
    
    BITree(int n)
    {
        tree.resize(n);
        fill(tree.begin(), tree.end(), 0);
    }
    
    void update(int i, int val)
    {
        while(i<tree.size())
        {
            tree[i]+=val;
            i+=(i&-i);
        }
    }
    
    int sum(int i)
    {
        int val=0;
        
        while(i>0)
        {
            val+=tree[i];
            i-=(i&-i);
        }
        return val;
    }
};

class Solution 
{
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n,0);
        
        if(n==0)
            return ans;
        
        int mini= *min_element(nums.begin(), nums.end());
        int maxi= *max_element(nums.begin(), nums.end());
        int range= maxi-mini+2;
        
        BITree tree(range);
        
        for(int i=n-1;i>=0;i--)
            ans[i]= tree.sum(nums[i]-mini), tree.update(nums[i]-mini+1, 1);
        
        return ans;
        
    }
};