class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        map<int, int> mp;
        int sum = 0;
        mp.insert({0,-1});
        
        for(int i = 0; i < nums.size(); i++) 
        {
            sum += nums[i];
            int r = sum%k;
            if(mp.find(r) != mp.end() && i-mp[r] > 1) 
                return true;
            else mp.insert({r, i});
        }
        return false;
    }
};