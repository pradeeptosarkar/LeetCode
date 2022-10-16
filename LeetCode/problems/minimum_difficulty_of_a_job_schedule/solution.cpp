class Solution {
private:
    int dp[11][301];
    
    int memorization(vector<int>& a, int d, int start)
    {
        if(d <= 0 && start>= a.size())  
            return 0;
        if(start >= a.size() || d<= 0)  
            return 1e9;
        if(dp[d][start] != -1)  
            return dp[d][start];
        
        int maxx = 0;
        int ans = INT_MAX;
        
        for(int i = start; i<a.size(); i++)
        {
            maxx = max(a[i], maxx);
            ans = min(ans, maxx + memorization(a, d-1, i+1));
        }
        
        return dp[d][start] = ans;
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        memset(dp, -1, sizeof(dp));
        int ans = memorization(jobDifficulty, d, 0);
        
        return ans < 1e9 ? ans : -1;        
    }
};