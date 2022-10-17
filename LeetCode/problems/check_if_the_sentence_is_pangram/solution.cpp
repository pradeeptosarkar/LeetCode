class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        unordered_set<char> s(begin(sentence), end(sentence));

        return s.size()==26;
    }
};