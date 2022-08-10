class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        unordered_map<long long,long long> mp;
        
        long long n=nums.size();
        long long ans = (n*(n-1))/2;
        
        for(long long i=0;i<n;i++)
            mp[nums[i]-i]++;
        
        for(auto i:mp)
        {
            if(i.second>1)
                ans-=(i.second*(i.second-1))/2;            
        }
        return ans;        
    }
};