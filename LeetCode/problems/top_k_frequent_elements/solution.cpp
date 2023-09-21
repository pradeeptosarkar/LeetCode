class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        
        for(auto i:nums)
            mp[i]++;
        
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        
        for(auto i:mp)
            pq.push(make_pair(i.second,i.first));
        
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};