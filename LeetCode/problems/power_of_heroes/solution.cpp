class Solution {
public:
    int sumOfPower(vector<int>& v) 
    {
        long long mod = 1e9+7;       
        sort(v.begin(), v.end()); 
     
        long long mini=0;
        long long sum=0; 
     
        for (int i=0; i<v.size(); i++) 
        { 
            sum=(sum + (((long long)v[i] * (long long)v[i]) % mod)*v[i]%mod) % mod; 
            sum=(sum + ((mini * (long long)v[i]) % mod)*(long long)v[i]%mod) % mod; 
            
            mini*=2;
            mini%=mod;
            mini+=v[i];
            mini%= mod; 
        } 
     
        int ans = sum%mod; 
        
        return ans;        
    }
};