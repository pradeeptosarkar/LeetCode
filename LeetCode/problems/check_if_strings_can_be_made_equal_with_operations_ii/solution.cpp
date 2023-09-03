class Solution {
public:
    bool checkStrings(string s1, string s2) 
    {
        if(s1==s2)
            return true;
        
        vector<int> oddCount(26,0);
        vector<int> eveCount(26,0);
        
        for(int i=0;i<s1.length();i++)
        {
            if(i%2)
            {
                oddCount[s1[i]-'a']++;
                oddCount[s2[i]-'a']--;
            }
            
            else
            {
                eveCount[s1[i]-'a']++;
                eveCount[s2[i]-'a']--;
            }
        }
        
        for(int i=0;i<26;i++)
            if(oddCount[i]!=0 or eveCount[i]!=0)
                return false;
        
        return true;
    }
};