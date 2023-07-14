class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        int ans=1;
        unordered_map<int,int> mp;
        
        for(auto i:arr)
        {
            mp[i]=mp[i-difference]+1;
            ans=max(ans, mp[i]);
        }
        
        return ans;
    }
};