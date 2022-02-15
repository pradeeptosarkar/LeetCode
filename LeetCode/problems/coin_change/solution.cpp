class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        int dp[n + 1];        

        for(int i {0}; i < n + 1; i++)

        {

            if(i == 0)

            {

                dp[i] = 0;

            }

            else

            {

                int mini = INT_MAX;

                for(int& coin : coins)

                {

                    if(i - coin > -1)

                    {

                        mini = min(mini, dp[i - coin]);

                    }

                }

                dp[i] = mini == INT_MAX ? mini : mini + 1;

            }

        }        

        

        return dp[n] == INT_MAX ? -1 : dp[n];

    
    }
};