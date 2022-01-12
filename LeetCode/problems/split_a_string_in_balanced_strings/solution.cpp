class Solution {
public:
    int balancedStringSplit(string s) {
        int c = 0;
        int res = 0;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'L')
            {
                c++;
            }
            else{
              c--;  
            }
            
            if(c == 0)
            {
                res++;
            }
        }
        return res;
    }
};