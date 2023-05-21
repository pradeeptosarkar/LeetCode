class Solution {
public:
    string makeSmallestPalindrome(string s) 
    {
        int i=0, j=s.length()-1;
        
        for(i,j; i<=j; i++,j--)
        {
            if(s[i]!=s[j])
            {
                s[j]=min(s[i], s[j]);
                s[i]=s[j];
            }
        }
        return s;
    }
};