class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        string result="";

        for (char c : num) 
        {
            while (k > 0 && !result.empty() && result.back() > c) 
            {
                result.pop_back();
                k--;
            }
            
            if (result.empty() && c == '0') 
                continue; 
            
            result.push_back(c);
        }

        result.erase(0, result.find_first_not_of('0'));
        
        if(result.size()<=k)
        return "0";
        result.resize(result.size() - k);

        return result.empty() ? "0" : result;
    }
};
