class Solution {

public:

    int numSubmatrixSumTarget(vector<vector<int>>& g, int target) {

        int n=g.size(), m=g[0].size(), ans=0;

        for(int left=0; left<m; left++){

            vector<int> tmp(n, 0);

            for(int right=left; right<m; right++){

                for(int i=0; i<n; i++)

                    tmp[i]+=g[i][right];

                unordered_map<int, int> mp;

                mp[0]=1;

                int sum=0;

                for(int i=0; i<n; i++){

                    sum+=tmp[i];

                    ans+=mp[sum-target];

                    mp[sum]++;

                }

            }

        }

        return ans;

    }

};
        

