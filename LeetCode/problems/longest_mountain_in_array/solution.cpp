class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> a(n);
        vector<int> b(n);
        
        if(n<3)
            return 0;
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
                a[i]=0, b[n-i-1]=0;
            
            else
            {
                if(arr[i]>arr[i-1]) a[i]=a[i-1]+1;
                else a[i]=0;
                
                if(arr[n-i-1]>arr[n-i]) b[n-i-1]=b[n-i]+1;
                else b[n-i-1]=0;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
            if(a[i]+b[i]>0 and a[i]>0 and b[i]>0)
                ans=max(ans,(a[i]+b[i]+1));
        
        return ans;
    }
};