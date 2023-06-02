class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        //int lastPoint=-1;
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]>ans.back()[1])
                ans.push_back({intervals[i][0], intervals[i][1]});
            
            else
            {
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
                //ans.back()[0]=min(ans.back()[0], intervals[i][0]);
            }
                
        }
        return ans;
    }
};