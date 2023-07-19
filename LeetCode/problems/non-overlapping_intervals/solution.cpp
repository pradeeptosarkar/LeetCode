class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
     sort(intervals.begin(),intervals.end());
        int l = intervals[0][0];
        int r = intervals[0][1];
        int cnt = 0;
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] >= r)
            {
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else
            {
                r = min(r,intervals[i][1]);
                cnt++;
            }
        }    
        return cnt;   
    }
};