class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        for(int i=1;i<word.length();i++)
            if((isupper(word[1])!=isupper(word[i])) or (islower(word[0]) and isupper(word[i])))
               return false;
        return true;
    }
};