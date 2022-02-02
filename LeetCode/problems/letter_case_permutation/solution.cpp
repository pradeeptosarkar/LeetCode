class Solution {
public:
    vector<string> letterCasePermutation(const string &s) {
        vector<string> result;
        helper(s, result, 0);
        return result;
    }
    
    void helper(const string &s, vector<string> &result, const int& i)
    {
        if(i >= s.size())
        {
            result.push_back(s);
            return;
        }

        if(isalpha(s[i]) != 0)
        {
            string temp = s;
			// change current char from upper to lower, or lower to upper
            temp[i] = (islower(s[i]) != 0) ? toupper(temp[i]) : tolower(temp[i]);

            helper(temp, result, i + 1); // change path 
        }
        
        helper(s, result, i + 1); // unchange + numbers path   
    }
};