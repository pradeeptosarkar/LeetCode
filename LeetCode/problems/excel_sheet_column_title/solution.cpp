class Solution {
public:
    string convertToTitle(int n) 
    {
        string ans;
        
        while(n)
        {
            ans.insert(ans.begin(),'A'+(n-1)%26);
            n=(n-1)/26;
        }
        return ans;
    }
};