class Solution {
public:
    int minMovesToMakePalindrome(string s) 
    {
        int ans=0;
        int n=s.length();
        int left=0, right=n-1;
        
        while(left<right)
        {
            int l=left, r=right;
            
            while(s[l]!=s[r])
                r--;
            
            if(l==r)
            {
                swap(s[r], s[r+1]);
                ans++;
                continue;
            }
            
            else
            {
                while(r<right)
                {
                    swap(s[r], s[r+1]);
                    r++;
                    ans++;
                }
            }
            
            left++, right--;
        }
        
        return ans;
    }
};
