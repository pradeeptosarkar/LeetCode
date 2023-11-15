class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> v(n+1,0);
        
        for(int i:arr)
            v[min(i,n)]+=1;
        
        int ans=1;
        
        for(int i=2;i<=n;i++)
            ans=min(ans+v[i], i);
        
        return ans;
    }
};