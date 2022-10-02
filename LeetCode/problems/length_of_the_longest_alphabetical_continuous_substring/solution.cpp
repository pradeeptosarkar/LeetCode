class Solution {
public:
    int longestContinuousSubstring(string s) 
    {
        int temp=1, ans=1;
    
		for(int i=0;i<s.length()-1;i++)
		{
			if(s[i]+1==s[i+1])
            {
				temp++;
				ans = max(temp,ans);
			}
            
			else
				temp = 1;
			
		}
		return ans;
    }
};