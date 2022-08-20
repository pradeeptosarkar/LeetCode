class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        int ans=0;
        int i=0;
        priority_queue<int> pq;
        
        for(ans; startFuel<target; ans++)
        {
            while(i<stations.size() and stations[i][0]<=startFuel)
            {
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty())
                return -1;
            else
            {startFuel+=pq.top(); pq.pop();}
        }
        return ans;
        
    }
};