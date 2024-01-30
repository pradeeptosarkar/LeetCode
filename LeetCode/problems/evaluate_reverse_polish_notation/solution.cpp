class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> stk;
        
        for(auto i:tokens)
        {
            if(i=="+" or i=="-" or i=="*" or i=="/")
            {
                int num1 = stk.top();
                stk.pop();
                
                int num2 = stk.top();
                stk.pop();
                
                int ans=0;
                
                if(i=="+") ans=num1+num2;
                else if(i=="-") ans=num2-num1;
                else if(i=="*") ans=num2*num1;
                else ans=num2/num1;
                
                stk.push(ans);
            }
            
            else
                stk.push(stoi(i));
        }
        
        return stk.top();
    }
};