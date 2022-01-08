class Solution {
public:
    int getMaxLen(vector<int>& nums) {
     int n=nums.size();
        
        int ans=0;
        
        for(int i=0;i<n;)
        {
            int start=i;
            while(start<n&&nums[start]==0)
                start++;
            int end=start;
            int start_n=-1;
            int end_n=-1;
            int count_negative=0;
            while(end<n&&nums[end]!=0)
            {
                if(nums[end]<0)
                {
                    count_negative++;
                    if(start_n==-1)
                        start_n=end;
                    end_n=end;
                }
                end++;
                    
            }
            if(count_negative%2==0)
                ans=max(ans,end-start);
            else
            {
                if(start_n!=-1)
                    ans=max(ans,end-start_n-1);
                if(end_n!=-1)
                    ans=max(ans,end_n-start);
                
            }
            i=end+1;
        }
        return ans;
    }
};