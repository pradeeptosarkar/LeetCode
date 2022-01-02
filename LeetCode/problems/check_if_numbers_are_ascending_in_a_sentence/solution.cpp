class Solution {
public:
    bool areNumbersAscending(string s) {
    string temp = "";
    int count = 0;
    vector<string> words;
        for(int i = 0; i <= s.size(); i++)
    {

        if(s[i] != ' ' && s[i] != '\0')
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                
            }
            else
            {
                temp += s[i];
                count++;
            }
            
        }
        else
        {
            if(count > 0)
            {
                words.push_back(temp);
                temp = ""; 
                count = 0;
            }
        }

        
    }
    
    bool result = true;
    int val1 = 0;
    int val2 = 0;
    
    for(int i = 0; i < words.size() - 1; i++)
    {
        
        val1 = stoi(words[i],nullptr,10);
        val2 = stoi(words[i+1],nullptr,10);
        if(val1 < val2)
        {
            result &= true;
        }
        else
        {
            result &= false;
        }
    }
    
    
    return result;    
    }
};