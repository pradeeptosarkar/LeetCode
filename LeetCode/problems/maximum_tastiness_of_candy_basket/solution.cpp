class Solution {
public:
    
    bool check(int &x, int k, vector<int>& price)
    {
        int cnt=0, pre=-x;
        
        for(auto i:price)
        {
            if(i-pre>=x)
            {
                pre=i;
                ++cnt;
            }
        }
        
        return cnt>=k;
    }
    
    int maximumTastiness(vector<int>& price, int k) 
    {
        int n=price.size();
        sort(price.begin(), price.end());
        int left=0, right=price[n-1]-price[0];
        
        while(right>left)
        {
            int mid=(right+left+1)/2;
            
            if(check(mid, k, price))
                left=mid;
            else
                right=mid-1;
        }
        
        return left;
    }
};