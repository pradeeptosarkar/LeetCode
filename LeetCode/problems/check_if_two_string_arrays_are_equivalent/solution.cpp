class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string a=word1[0];
        string b=word2[0];
        
        for(int i=1;i<word1.size();i++)
            a+=word1[i];
        for(int i=1;i<word2.size();i++)
            b+=word2[i];
        
        if(a==b)
            return true;
        else
            return false;
    }
};