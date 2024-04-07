class Solution {
public:
    bool checkValidString(string s) 
    {
        stack<char> open, stars;
        
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            
            if(c=='(')
                open.push(i);
            else if(c=='*')
                stars.push(i);
            else
            {
                if(!open.empty())
                    open.pop();
                else if(!stars.empty())
                    stars.pop();
                else
                    return false;
            }
        }
        
        while(!open.empty() and !stars.empty())
        {
            if(open.top()>stars.top())
                return false;
            open.pop();
            stars.pop();
        }
        
        return open.empty();
    }
};
