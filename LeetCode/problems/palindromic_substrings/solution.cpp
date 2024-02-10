class Solution {
public:
    
    int countPal(string s, int i, int j)
    {
        int count=0;
        while(i>=0 and j<s.size() and s[i]==s[j])
            i--, j++, count++;
        
        return count;
    }
    
    int countSubstrings(string s) 
    {
        int ans=0;
        for(int i=0; i<s.size(); i++)
            ans+= countPal(s, i, i) + countPal(s, i, i+1);
        
        return ans;
    }
};