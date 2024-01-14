class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.length()!=word2.length())
            return false;
        
        vector<int> count1(26,0), count2(26,0);
        vector<bool> check1(26,false), check2(26, false);
        
        for(int i=0;i<word1.size();i++)
        {
            count1[word1[i]-'a']+=1;
            check1[word1[i]-'a']=true;
            
            count2[word2[i]-'a']+=1;
            check2[word2[i]-'a']=true;
        }
        
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        
        return count1==count2 and check1==check2;
    }
};