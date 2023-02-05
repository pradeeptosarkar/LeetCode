class Solution {
public:
    
    bool isAVowel(char x)
    {
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u')
            return true;
        
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        vector<int> prefix(words.size()+1, 0), ans;
        
        for(int i=0;i<words.size();i++)
            prefix[i+1] = prefix[i] + (isAVowel(words[i][0]) and isAVowel(words[i][words[i].size()-1]));
        
        for(int i=0;i<queries.size();i++)
            ans.push_back(prefix[queries[i][1] + 1] - prefix[queries[i][0]]);
            
        return ans;
    }
};