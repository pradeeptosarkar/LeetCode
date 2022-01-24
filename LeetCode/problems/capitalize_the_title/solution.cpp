class Solution {
    string res = "";
    
public:
    void insert(int l, int r, string s)
    {
        if(r-l > 2)
        {
            if(s[l] >= 'A' && s[l] <= 'Z')  res += s[l];
            else    res += (char) ((int) s[l] - 32);
            l++;
        }
        while(l < r)
        {
            if(s[l] >= 'A' && s[l] <= 'Z')      
                res += (char) (((int) s[l]) + 32);
            else    
                res += s[l];
            l++;
        }
        if(r != s.length())     res += " ";
    }
    
    string capitalizeTitle(string s) 
    {
        int l = 0, r = 0, n = s.length();
        while(r < n)
        {
            if(s[r] == ' ')
            {
                insert(l, r, s);
                l = r+1;
            }
            r++;
        }
        insert(l, r, s);
        return res;
    }
};