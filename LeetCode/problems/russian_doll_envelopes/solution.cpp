class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        vector<int> DP(n,1);
        int longest = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][1]>envelopes[j][1]&& envelopes[i][0]>envelopes[j][0] && DP[i]<DP[j]+1)
                {
                    DP[i]=DP[j]+1;
                    longest = max(longest, DP[i]);
                }
            }
        }        
        return longest;
    }
};