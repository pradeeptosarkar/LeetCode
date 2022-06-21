class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int n=heights.size()-1;
        priority_queue<int, vector<int>, greater<int>> pq;
        int req_sum=0;
        
        for(int i=1;i<=n;i++)
        {
            int diff=heights[i]-heights[i-1];
            
            if(diff<=0)
                continue;
            
            pq.push(diff);
            
            if(pq.size()>ladders)
                req_sum+=pq.top(), pq.pop();
            if(req_sum>bricks)
                return i-1;
        }
        
        return n;
        
    }
};