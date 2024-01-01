class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int ans=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i=g.size()-1;
        int j=s.size()-1;
        
        while(true)
        {
            if(i<0 or j<0)
                break; 
            
            if(g[i]<=s[j]) {i--,j--, ans+=1;}
            
            else
                i--;
        }
        
        return ans;
    }
};