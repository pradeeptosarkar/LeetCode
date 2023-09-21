class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> stk;
        
        for(auto i:s)
        {
            if(i=='(' or i=='{' or i=='[')
                stk.push(i);
            
            else
            {
                if((i==')' or i=='}' or i==']') and (stk.empty()))
                    return false;
                
                if(i==')' and stk.top()=='(') stk.pop();
                else if(i=='}' and stk.top()=='{') stk.pop();
                else if(i==']' and stk.top()=='[') stk.pop();
                
                else return false;
            }
        }
        
        return stk.empty();
    }
};