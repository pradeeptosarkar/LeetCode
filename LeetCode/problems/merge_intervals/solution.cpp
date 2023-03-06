class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        for(int i=0;i<intervals.size();i++)
        {
            if(ans.empty() or ans.back()[1]<intervals[i][0])
            {
                vector<int> temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                ans.push_back(temp);
            }
            
            else
            {
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};