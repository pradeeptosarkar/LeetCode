class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<int>cur((sum/2) +1,0),prev((sum/2) +1,0);
        cur[0]=true;
        for(int i=0;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                if(j-nums[i]>=0){
                    cur[j]=prev[j-nums[i]];
                }
                cur[j]|=prev[j];
            }
            prev=cur;
        }
        return prev[sum/2];
    }
};