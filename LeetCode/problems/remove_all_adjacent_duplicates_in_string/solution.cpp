class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> stk;
        
        for(auto i:s)
        {
            if(stk.empty())
                stk.push(i);
            
            else
            {
                if(stk.top()==i)
                    stk.pop();
                else
                    stk.push(i);
            }
        }
        string ans="";
        
        while(!stk.empty())
        {
            ans=stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};