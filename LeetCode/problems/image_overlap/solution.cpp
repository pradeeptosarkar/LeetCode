class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        int i,ans=0,n=img1.size();
        vector<int> a, b;
        unordered_map<int,int> mp;
        
        for (i=0; i<n*n; i++) 
        {
            if (img1[i/n][i%n])
                a.push_back(i/n*100+i%n);
            if (img2[i/n][i%n])
                b.push_back(i/n*100+i%n);
        }
        
        for (auto i:a)
            for (auto j:b)
                mp[i-j]++;
        
        for (auto c:mp)
            ans = max(ans,c.second);
        
        return ans;
        
    }
};