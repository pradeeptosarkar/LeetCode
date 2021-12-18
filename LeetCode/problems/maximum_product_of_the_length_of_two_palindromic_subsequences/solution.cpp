class Solution {
public:
    int ans=1;
    int LCS(string s){
        int n=s.size();
        string s1=s,s2=string(s.rbegin(),s.rend());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
                }
            }
        }
        return dp[n][n];
    }
    int maxProduct(string s) {
        int n=s.size();
        for (int m=0;m<(1<<n);m++){
            string s1="",s2="";
            for (int i=0;i<n;i++){
                if ((m & (1<<i))!=0){
                    s1+=s[i];
                }
                else {s2+=s[i];}
            }
            if(s1!="" && s2!="") ans=max(ans,LCS(s1)*LCS(s2));
            if ((n%2==0 && ans==(n*n)/4) || (n%2==1 && ans==(n-1)*(n+1)/4))  break;
        }
        return ans;
    }
};