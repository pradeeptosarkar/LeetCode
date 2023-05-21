class Solution {
public:
    int minLength(string s) 
    {
        stack<char> stk;
    
        for(auto c:s) 
        {
        if (stk.size()==0 or stk.top()!='A' and stk.top()!='C') 
            stk.push(c);
            
        else if ((stk.top()=='A' and c=='B') or (stk.top()=='C' and c=='D')) 
            stk.pop();
        
        else 
            stk.push(c);
    }
    return stk.size();
        
    }
};