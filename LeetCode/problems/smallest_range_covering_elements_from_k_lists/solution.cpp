class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int n = nums.size();
        vector<pair<int,int>>arr;
        
        for(int i =0;i<n; i++)
            for(auto j : nums[i])
                arr.push_back({j,i});
            
        
        sort(arr.begin(),arr.end());
        
        int req = n;
        int cnt = 0;
        int x = -1,y = -1;
        vector<int>mp(n,0);
        int j = 0;
        
        for(int i = 0; i<arr.size() ; i++)
        {
            mp[arr[i].second]++;
            
            if(mp[arr[i].second]==1) 
                cnt++;
            
            if(cnt==req)
            {
                int t1 = arr[j].first;
                int t2 = arr[i].first;
                if((x==-1&&y==-1)||t2-t1<y-x)
                    x = t1, y = t2;
                
                while(j<i&&cnt==req)
                {
                    mp[arr[j].second]--;
                    if(mp[arr[j].second]==0) 
                        cnt--;
                    
                    j++;
                    
                    if(cnt==req)
                    {
                        int t1 = arr[j].first;
                        int t2 = arr[i].first;
                        if((x==-1&&y==-1)||t2-t1<y-x)
                            x = t1, y = t2;
                        
                    }
                }
            }
        }
        
        return {x,y};
        
    }
};