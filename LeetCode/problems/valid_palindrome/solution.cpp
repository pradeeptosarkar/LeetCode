class Solution {
public:
    char tolowercase(char a)
    {
        if((a>='a' and a<='z') ||(a>='0' and a<='9'))
            return a;
        else
            return a-'A'+'a';
    }
    bool isAlphaNum(char a)
    {
        if((a>='a' and a<='z')||(a>='A' and a<='Z')||(a>='0' and a<='9'))
            return 1;
        return 0;
    }
    bool isP(string s)
    {
        int i=0;
        int e=s.length()-1;
        while(i<e)
        {
            if(tolowercase(s[i])!=tolowercase(s[e]))
                return 0;
            else
            {
                i++;
                e--;
            }
        }
        return 1;
    }
    bool isPalindrome(string s) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(isAlphaNum(s[i]))
                ans+=s[i];
        }
        return isP(ans);
        
    }
};