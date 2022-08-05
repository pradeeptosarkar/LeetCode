class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<unsigned long long> ans(target+1,0);
        sort(nums.begin(), nums.end());
        ans[0]=1;
        
        for(int i=1;i<=target;i++)
        {
            for(int j:nums)
                if(i>=j)
                    ans[i]+=ans[i-j];
        }
        return ans[target];
    }
};