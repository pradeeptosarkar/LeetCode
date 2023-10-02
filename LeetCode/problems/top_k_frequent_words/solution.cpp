class Solution {
public:
    class cmp
    {  
        public:
        bool operator()( pair<int,string> &p1,const pair<int,string> &p2)
        {
            if(p1.first==p2.first) 
                return p1.second>p2.second;
            
            return p1.first<p2.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> mp;  
        
        for(int i=0;i< words.size();i++)
            mp[words[i]]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq; 
        
        for(auto it: mp)
            pq.push({it.second,it.first});  
        
        vector<string> ans;  
         
        while(!pq.empty() && k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
       
        return ans;
    }
};