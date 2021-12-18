class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int n = s.size();
        int m;
        char t;
        int j = n - 1;
        
        if(n % 2 == 0)
            m = (n / 2) - 1;
        else
            m = n / 2;
        
        for(int i=0; i<=m; i++)
        {
            t = s[i];
            s[i] = s[j];
            s[j] = t;
            j--;
        }
    }
};