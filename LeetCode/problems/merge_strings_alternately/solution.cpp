class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int n=0;
        
        if(word1.size()<word2.size())
            n=word1.size();
        else
            n=word2.size();
        
        int i=0;
        string ans="";
        
        while(i<n)
        {
            ans+=word1[i];
            ans+=word2[i];
            i++;
        }
        if(word1[i]!=NULL){
            while(i<word1.size())
            {
                ans+=word1[i];
                i++;
            }
        }
        else{
            while(i<word2.size())
            {
                ans+=word2[i];
                i++;
            }
        }
        return ans;
    }
};