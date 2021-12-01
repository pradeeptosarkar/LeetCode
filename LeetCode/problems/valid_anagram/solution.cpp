class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
      map<char,int> a;
      map<char,int> b;
        
        for(int i=0;i<s.size();i++)
            a[s[i]]++;
        
        for(int i=0;i<t.size();i++)
            b[t[i]]++;
        
        int Max = max(a.size(),b.size());
        
        for(int i=0;i<Max;i++)
        {
            if(a[s[i]]!=b[s[i]])
                return false;
            
            else if(a[t[i]]!=b[t[i]])
                return false;
        }
        return true;
    }
};