class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        map<string,int>m1;
        for(string str: words)
            if(str[0] != str[1])
                m1[str]++;
            
        
        int ans = 0;
        for(auto &i : m1)
        {
            string temp = i.first;
            int val1 = i.second;
            reverse(temp.begin(),temp.end());
            int val2 = m1[temp];
            ans += (min(val1,val2))*2;
        }
        
        map<string,int>m;
        for(string str: words)
            if(str[0] == str[1])
                m[str]++;
            
        
        bool oddIsPresent = false;
        for(auto &i : m)
        {
            if(i.second%2 == 0) 
                ans +=(i.second*2);
            
            else 
            {
                ans += (i.second-1)*2;
                oddIsPresent = true;
            }
        }
        ans += (oddIsPresent*2);
        return ans;
    }
};