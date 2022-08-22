class Solution {
public:
    string makeGood(string s) 
    {
        for(int i=0;i<s.size();i++)
            if(abs(s[i]-s[i+1])==32)
                s.erase(i,2),i=max(i-2, -1);
        
        return s;
    }
};