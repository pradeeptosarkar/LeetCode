class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int,int> > v; int i;
        for(i=0;i<nums.size();i++) 
            v.push_back({nums[i],i});
        sort(v.begin(),v.end()); int prev = 0;
        for(i=1;i<v.size();i++)
            if(v[i].first!=v[i-1].first) {
                nums[v[i].second] = i;
                prev = i;
            }
        else
            nums[v[i].second] = prev;
        nums[v[0].second] = 0;
        return nums;
    }
};