class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n,-1);
        
        stack<pair<int,int>> st;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            
            while(pq.size() and curr>pq.top().first)
            {
                ans[pq.top().second]=curr;
                pq.pop();
            }
            
            while(st.size() and curr>st.top().first)
            {
                pq.push(st.top());
                st.pop();
            }
            
            st.push({curr,i});
        }
        return ans;
        
    }
};