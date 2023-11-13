class Solution {
public:
    
    bool isVowel(char c) 
    {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    
    string sortVowels(string s) 
    {
        unordered_map<char, int> count;

        for (char c : s) 
            if (isVowel(c)) 
                count[c]++;
        
        string sortedVowel = "AEIOUaeiou";
        string ans;
        int j = 0;
        
        for (int i = 0; i < s.size(); i++) 
        {
            if (!isVowel(s[i])) 
                ans += s[i];
            
            else 
            {
                while (count[sortedVowel[j]] == 0) 
                {
                    j++;
                }

                ans += sortedVowel[j];
                count[sortedVowel[j]]--;
            }
        }
        
        return ans;
    }
};