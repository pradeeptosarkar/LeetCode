class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        vector<int> counts(26, 0);
        
        for (char c : chars) 
            counts[c - 'a']++;
        
        int ans = 0;
        for (string word : words) 
        {
            vector<int> wordCount(26, 0);
            for (char c : word) 
                wordCount[c - 'a']++;
            
            bool good = true;
            for (int i = 0; i < 26; i++) 
            {
                if (counts[i] < wordCount[i]) 
                {
                    good = false;
                    break;
                }
            }
            
            if (good) 
                ans += word.size();
            
        }
        return ans;
    }
};