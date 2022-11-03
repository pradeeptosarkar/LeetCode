class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        vector<pair<int, int>>gardenInfo;
        int n = plantTime.size();
        
        for(int i=0; i<n; i++)
            gardenInfo.push_back(make_pair(growTime[i], plantTime[i]));
        
        sort(gardenInfo.begin(), gardenInfo.end(), greater<pair<int, int>>());
        
        int total_day = 0, day_by_plant = 0;
        
        for(int i=0; i<n; i++)
        {
            day_by_plant += gardenInfo[i].second;
            total_day = max(total_day, day_by_plant + gardenInfo[i].first);
        }
        return total_day;
    }
};