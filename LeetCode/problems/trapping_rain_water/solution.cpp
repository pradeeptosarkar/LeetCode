class Solution {
public:
    int trap(vector<int>& height) 
    {
       int temp, ans=0;
       int n=height.size();
       int maxLeft[n]; int maxRight[n];
       maxLeft[0]=0;
       maxRight[n-1]=0;
        
       for(int i=1;i<n;++i)
       {
           maxLeft[i]=max(maxLeft[i-1], height[i-1]);
           maxRight[n-1-i]=max(maxRight[n-i], height[n-i]);
       } 
        
       for(int i=0;i<n;++i)
       {
           temp=min(maxLeft[i], maxRight[i])-height[i];
           
           if(temp>0)
               ans+=temp; 
       }
       return ans;
    }
};