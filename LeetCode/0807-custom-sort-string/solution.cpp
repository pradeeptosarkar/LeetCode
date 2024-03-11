class Solution {
    public:
    string customSortString(string order, string s) {
        
        unordered_map<char, int> freq;

        for (char letter : s) 
            freq[letter]++;
        
        string result = "";
        
        for (char c : order) 
            while (freq[c]-- > 0) 
                result += c;
        
        for (auto & [letter, count] : freq) 
            while (count-- > 0) 
                result += letter;
            
        return result;
    }
};
