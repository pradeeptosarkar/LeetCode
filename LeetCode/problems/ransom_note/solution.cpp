class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int> count(26);
        
        for(char c : magazine){
            count[c-'a'] += 1;
        }
        
        for(char c : ransomNote){
            count[c-'a'] -= 1;
            if(count[c-'a'] < 0) return false;
        }
        
        return true;
    }
};