class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) 
    {
        unordered_map<long long int, vector<long long int>> mp;
        long long int ans=0;
        
        for(long long int i=0;i<tasks.size();i++)
        {
            if(mp[tasks[i]].empty())
                mp[tasks[i]].push_back(++ans);
            else if((ans-mp[tasks[i]].back())>space)
                mp[tasks[i]].push_back(++ans);
            else
            {
                ans=mp[tasks[i]].back()+space+1;
                mp[tasks[i]].push_back(ans);
            }
        }
        return ans;
        
    }
};