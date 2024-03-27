class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) 
    {
        int ans=0;
        int n=reward1.size();
        
        for(auto i:reward2)
            ans+=i;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push(reward1[i]-reward2[i]);
            
            if(pq.size()>k)
                pq.pop();
        }
        
        while(!pq.empty())
            ans+=pq.top(), pq.pop();
        
        return ans;
    }
};
