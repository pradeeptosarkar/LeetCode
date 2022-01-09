class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int > ans(nums.size());
        
        // at ith index in nums, stored the xor all element till i
        for(int i=1;i<nums.size();i++)
        {
            nums[i]^=nums[i-1];
        }
        
        // loop the array in reverse order 
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[nums.size()-i-1]=nums[i]^((1<<maximumBit) - 1);// will always make the maximum xor as (1<<maximumBit - 1)
        }
        return ans;
    }
};