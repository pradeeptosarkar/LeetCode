class Solution {
public:
    
    static bool cmp(pair<int,string>&a, pair<int,string>&b)
    {
        if(a.first==b.first)
            return b.second>a.second;
        
        return a.first>b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> mp;
        for(auto i:words)
            mp[i]++;
        
        vector<pair<int,string>> q;
        
        for(auto i:mp)
            q.push_back(make_pair(i.second, i.first));
        
        sort(q.begin(),q.end(),cmp);
        vector<string> ans;
        
        for(int i=0;i<k;i++)
            ans.push_back(q[i].second);
        
        return ans;
    }
};