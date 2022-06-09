class Solution {
public:
    
    bool checkIfPali(string s)
    {
        int i=0;
        int j=s.size()-1;
        
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            else
                i++, j--;
        }
        return true;
    }
    
    int removePalindromeSub(string s) 
    {
        if(checkIfPali(s))
            return 1;
        else
            return 2;
    }
};