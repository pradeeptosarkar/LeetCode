class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int ans=strs[0].length();
        
        for(int i=1;i<strs.size();i++)
        {
            int j=0;
            
            while(j<strs[i].length() and strs[i][j]==strs[0][j])
                j++;
            
            ans=min(ans,j);
        }
        
        return strs[0].substr(0,ans);
    }
};