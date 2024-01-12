class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int ans=0;
        int n=s.size();
        
        for(int i=0;i<n;i++)
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
                (i<n/2)?ans+=1:ans-=1;
            
        return !ans;
    }
};