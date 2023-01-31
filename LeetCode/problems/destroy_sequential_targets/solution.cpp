class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) 
    {
        unordered_map<int, pair<int, int>> mp;
        int ans=numeric_limits<int>::max();
        int mini=0;
        
        for(int i:nums) 
        {
            auto& p=mp[i%space];
            p.second=!p.first++ ? i:min(p.second, i);
            if(p.first>=mini) 
            {
                ans=p.first>mini ? p.second:min(ans, p.second);
                mini=p.first;
            }
        }
        return ans;
    }
};