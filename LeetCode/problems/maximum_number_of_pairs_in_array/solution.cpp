class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans={0,n};
        vector<int> check(101,0);
        for(int i=0;i<n;i++)
        {
            check[nums[i]]++;
            if(check[nums[i]]==2)
            {check[nums[i]]-=2; ans[0]+=1; ans[1]-=2;}
        }
        
        return ans;
        
    }
};