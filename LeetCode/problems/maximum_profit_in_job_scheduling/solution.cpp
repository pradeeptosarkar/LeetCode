class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        map<int, int> dp;
        vector<vector<int>> jobs;
        
        for (int i = 0; i < startTime.size(); i++) 
            jobs.push_back(vector<int>{startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        
        int ans=0;
        
        for (auto job : jobs) 
        {
            auto it = dp.lower_bound(job[1]);
            int pre = (it == dp.end()) ? 0 : it->second;
            ans = max(ans, job[2] + pre);
            dp[job[0]] = ans;
        }
        
        return ans;
    }
};