class Solution {
public:
    bool halvesAreAlike(string s) {
        
        string vowels = "aeiouAEIOU";
        int n = s.length();
        
        int alikeOne  = 0, alikeTwo = 0;
        
		//cout statements are for debugging purposes on a cpp compiler
        string halfOne = s.substr(0, (n/2));
        //cout << (n/2) - 1<< endl;
        //cout << halfOne << endl;
        string halfTwo = s.substr(n/2, n-1);
        //cout << halfTwo << endl;
        
        for(char ch : vowels)
        {
            for(char c: halfOne)
            {
                if(ch == c)
                {
                    alikeOne++;
                }
            }
            for(char c: halfTwo)
            {
                if(ch == c)
                {
                    alikeTwo++;
                }
            }
        }
        
        //cout << alikeOne << endl << alikeTwo << endl;
        
        if(alikeOne == alikeTwo)
        {
            return true;
        }
        
        
        return false;
        
    }
};