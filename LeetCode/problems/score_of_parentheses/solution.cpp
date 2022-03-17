class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        stack<int> stk;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                stk.push(-1);
            else
            {
                if(stk.top()==-1)
                {
                    stk.pop();
                    stk.push(1);
                }
                else
                {
                    int temp=0;
                    while(stk.top()!=-1)
                    {
                        temp+=stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    stk.push(2*temp);
                }
            }
        }
        
        int temp=0;
        while(stk.size()>0)
        {
            temp+=stk.top();
            stk.pop();
        }
        
        return temp;
    }
};