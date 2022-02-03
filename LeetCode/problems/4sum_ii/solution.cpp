class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        map<int,int> mp;
        
        for(auto x: nums1)
            for(auto y: nums2)
                mp[x+y]++;
        
        int ans=0;
        
        for(auto x: nums3)
            for(auto y: nums4)
                if(mp.count((-(x+y)))==1)
                    ans+=mp[-(x+y)];
        
        return ans;
        
    }
};