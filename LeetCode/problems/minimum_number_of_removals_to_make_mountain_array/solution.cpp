class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>LIS(n,1);
        vector<int>LDS(n,1);
        
        
        for(int i=0;i<n;i++)
        {  for(int j=i-1;j>=0;j--)                  // Longest Incresing Subsequence//
            {
                if(nums[i]>nums[j] && LIS[j]+1 > LIS[i])
                    LIS[i]=LIS[j]+1;
            }
            
        }
        for(int i=n-1;i>=0;i--)                   //Longest decresing subsequence[Increasing from end]//
        {  for(int j=i+1;j<n;j++)
            {
                if(nums[i]>nums[j] && LDS[j]+1 > LDS[i])
                    LDS[i]=LDS[j]+1;
            }
            
        }
        int maxx=0;
        for(int i=0;i<n;i++)
        {  if(LIS[i]>1 && LDS[i]>1)
            maxx=max(maxx,LIS[i]+LDS[i]-1);        //By considering every ele as peak,we find length of longest biotonic subseq 
        }
        return n-maxx;                           //Total length minus longest bitonic subsequence length
        
        
    }
};