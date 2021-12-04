class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> seen;
        map<char,char> closed{{')', '('}, {'}', '{'}, {']', '['},};
        
        for(auto c: s)
        {
            if(closed.find(c)!=closed.end())
            {
                char top = seen.empty() ? '_':seen.top();
                
                if(top!=closed[c])
                    return false;
                
                seen.pop();
            }
            
            else
                seen.push(c);
        }
        
        return seen.empty();
    }
};