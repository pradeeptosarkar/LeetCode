class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> stk;
        
        for(auto i:asteroids)
        {
            int flag=true;
            
            while(stk.size()>0 and (stk.top()>0 and i<0))
            {
                if(stk.top()<abs(i))
                {
                    stk.pop();
                    continue;
                }
                    
                
                else if(stk.top()==abs(i))
                    stk.pop();
                
                flag=false;
                break;
            }
            
            if(flag)
                stk.push(i);
        }
        
        vector<int> ans(stk.size());
        
        for(int i=stk.size()-1;i>=0;i--)
        {
            ans[i]=stk.top(); 
            stk.pop();
        }
        
        return ans;
    }
};