class Solution 
{
public:
    int firstUniqChar(string s) 
    {
      map<char,int> count;
        
        for(int i=0;i<s.size();i++)
            count[s[i]]++;
        
        for(int i=0;i<s.size();i++)
        {
            if(count[s[i]]==1)
                return i;
        }
        return -1;
    }
};