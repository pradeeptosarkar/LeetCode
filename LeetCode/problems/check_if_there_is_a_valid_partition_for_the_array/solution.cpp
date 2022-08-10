class Solution {
public:
    bool validPartition(vector<int>& a) 
    {
        int n=a.size();
        vector<int> t(n);
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]==a[i+1])
                if((i+2<n && t[i+2]) || i+2>=n)
                    t[i]=1;
    
            if(i+2<n && ((a[i]+1==a[i+1] && a[i]+2==a[i+2])||(a[i]==a[i+1] && a[i]==a[i+2])))
                if((i+3<n && t[i+3]) || i+3>=n)
                    t[i]=1;
        }
        return t[0];
    }
};