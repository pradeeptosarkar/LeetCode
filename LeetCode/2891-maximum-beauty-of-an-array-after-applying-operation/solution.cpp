class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            int ind = upper_bound(nums.begin(), nums.end(), nums[i] + 2*k) - nums.begin();
            ans = max(ans, ind-i);
        }
        
        return ans;
    }
};
