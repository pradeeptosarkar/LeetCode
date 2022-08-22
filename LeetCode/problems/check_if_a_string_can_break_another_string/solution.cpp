class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) 
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        if(s1==s2)
            return true;
        
        bool a=true,b=true;
        
        for(int i=0;i<s1.size();i++)
        {
            
            if(s1[i]<s2[i])
                a=false;
            if(s2[i]<s1[i])
                b=false;
        }
        if(a or b)
            return true;
        return false;
        
    }
};