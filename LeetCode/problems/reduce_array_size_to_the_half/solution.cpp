class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        int n=arr.size();
        int t=n/2;
        unordered_map<int,int> mp;
        
        for(int i:arr)
            mp[i]++;
        
        priority_queue<int> pq;
        
        for(auto i:mp)
            pq.push(i.second);
        int ans=0;
        
        while(n>t)
        {
            n-=pq.top();
            ans++;
            pq.pop();
        }
        return ans;
                
    }
};