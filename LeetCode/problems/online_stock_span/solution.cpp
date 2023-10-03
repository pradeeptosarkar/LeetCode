class StockSpanner {
public:
    
    stack<pair<int,int>> stk;
    
    StockSpanner() {
        
    }
    
    int next(int price) 
    {
        int ans=1;
        
        while(!stk.empty() and stk.top().first<=price)
        {
            ans+=stk.top().second;
            stk.pop();
        }
        
        stk.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */