class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) 
    {
        int n=security.size();
        vector<int> a(n);
        vector<int> b(n);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
                a[i]=0, b[n-i-1]=0;
            
            else
            {
                if(security[i]<=security[i-1])
                    a[i]=a[i-1]+1;
                else
                    a[i]=0;
                
                if(security[n-i-1]<=security[n-i])
                    b[n-i-1]=b[n-i]+1;
                else
                    b[n-i-1]=0;
            }
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++)
            if(a[i]>=time and b[i]>=time)
                ans.push_back(i);
        
        return ans;
    }
};