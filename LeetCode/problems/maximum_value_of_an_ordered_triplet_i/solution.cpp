class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        long long ans=0;
        long long a=nums[0];
        long long b=a-nums[1];
        
        for(int k=2;k<nums.size();k++)
        {
            ans=max(ans, b*nums[k]);
            a= ((long long)nums[k-1]>a) ? (long long)nums[k-1] : a;
            b= ((a-nums[k])>b) ? a-nums[k] : b;
        }
        
        return ans;

    }
};