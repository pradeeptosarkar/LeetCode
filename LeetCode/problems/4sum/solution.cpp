class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        
        if(n<4)
            return {};
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int front=j+1, back=n-1, y=nums[i]+nums[j], x=target-y;
                
                while(front<back)
                {
                    if(nums[front]+nums[back]<x)
                        front++;
                    else if(nums[front]+nums[back]>x)
                        back--;
                    
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[front],nums[back]});
                        
                        while(front<n-1 and nums[front]==nums[front+1])
                        {front++;}
                        while(back>0 and nums[back]==nums[back-1])
                        {back--;}
                        front++;
                        back--;
                    }
                    
                }
                while(j<n-1 and nums[j]==nums[j+1])
                {j++;}
            }
            while(i<n-1 and nums[i]==nums[i+1])
            {i++;}
                
            }
        return ans;
        }
        
    };
