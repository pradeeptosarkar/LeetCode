class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> count;
        int Max=1;
        for (const int num : nums)
            Max=max(Max, ++count[num]);
        map<int, vector<int>> bucket;
        for (auto kv : count)
            bucket[kv.second].push_back(kv.first);
        vector<int> ans;
        for(int i=Max;i>=1;--i) 
        {
            auto it=bucket.find(i);
            if(it == bucket.end()) 
                continue;
            ans.insert(ans.end(), it->second.begin(), it->second.end());
            if(ans.size() == k) 
                return ans;
        }
        return ans;
    }
};