class Solution {

public:

    int dp[101][21][101];

    int recur(int houseNo, int prevColor, int neighbours,vector<int>& houses, vector<vector<int>>& cost, int totalHouses, int totalColors, int target){

        if(target <neighbours){

            return INT_MAX/2;

        }

        if(dp[houseNo][prevColor][neighbours] !=-1){

            return dp[houseNo][prevColor][neighbours];

        }

        if(houseNo == totalHouses){

            return target==neighbours ? 0 : INT_MAX/2;

        }

        else{

            int ans = INT_MAX/2;

            if(houses[houseNo] == 0){

                for(int i = 0;i<totalColors;i++){

                    ans = min(ans,cost[houseNo][i] +recur(houseNo+1,i+1,(prevColor==i+1) ? neighbours :neighbours+1 , houses , cost, totalHouses, totalColors, target));

                }

            }

            else{

                ans = min(ans,recur(houseNo+1,houses[houseNo], (prevColor==houses[houseNo]) ? neighbours : neighbours+1, houses,cost,totalHouses,totalColors,target));

            }

            // cout<<ans<<endl;

            return dp[houseNo][prevColor][neighbours] = ans;

        }

    }

    

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        memset(dp,-1,sizeof(dp));

        int ans =  recur(0,0,0,houses,cost,m,n,target) ;

        return ans == INT_MAX/2 ? -1 : ans ;

    }

};
        

