class Solution {
public:
    long long totalCost(vector<int>& c, int k, int can) 
    {
        long long ans=0;
        if(c.size()==1) 
            return c[0];
        
        priority_queue<int,vector<int>,greater<int>> l,r;
        int left = 0,right=c.size()-1;
        
        for(int i=1;i<=can;i++)
        {
            if(i-1 >= c.size()-i) break;
            l.push(c[i-1]);left = i;
            r.push(c[c.size()-i]);right = c.size()-i-1;
        }
        
        bool f=1;
        
        while(k--)
        {
            if(left>right) 
                f=0;
            
            int a=!l.empty()?l.top():INT_MAX;
            int b=!r.empty()?r.top():INT_MAX;
            
            if(a<=b)
            {
                ans+=a;
                l.pop();
                if(f) 
                    l.push(c[left]);
                if(f) 
                    left++;
            }
            
            else
            {
                ans+=b;
                r.pop();
                if(f) 
                    r.push(c[right]);
                if(f) 
                    right--;
            }
        }
        return ans;
    }
};