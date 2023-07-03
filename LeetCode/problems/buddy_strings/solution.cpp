class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        if(s.size()!=goal.size())
            return false;
        
        if(s==goal)
        {
            vector<int> freq(26,0);
            
            for(char& c:s)
            {
                freq[c-'a']++;
                
                if(freq[c-'a']==2)
                    return true;
            }
            
            return false;
        }
        
        int a=-1, b=-1;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                if(a==-1)
                    a=i;
                else if(b==-1)
                    b=i;
                else
                    return false;
            }
        }
        
        if(b==-1)
            return false;
        
        return s[a]==goal[b] and s[b]==goal[a];
    }
};