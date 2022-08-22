class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        string temp=s;
        int n=s.size(), m=part.size();
        int i,j;
        
        for(i=0, j=0;i<n;i++)
        {
            temp[j++]=s[i];
            if(j>=m and temp.substr(j-m,m)==part)
                j-=m; 
        }
        return temp.substr(0,j);   
    }
};