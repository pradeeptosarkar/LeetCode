class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int ans=1;
        int endPoint=INT_MAX;
        sort(points.begin(), points.end());
        
        for(auto i:points)
        {
            int start=i[0];
            int end=i[1];
            
            if(endPoint<start)
            {
                ans++; 
                endPoint=end;
            }
            
            else
                endPoint=min(end, endPoint);
        }
        
        return ans;
    }
};
