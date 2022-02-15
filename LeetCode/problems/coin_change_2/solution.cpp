/* class Solution {
public:
    int change(int amount, vector<int>& coins) {
        Coin Change 2 : Recursion->DP

31

VIEWS

0

Created at: 3 days ago

manishk26122002

manishk26122002

 0

BRUTE FORCE: Recursion(TLE)

class Solution {

public:

int ans=0;

void helper(int i,int a, vector& coins,vector &tmp)

{

if(a==0)

{

ans++;

return;

}

if(a<0) return;

    if(i==coins.size()) return;

    

    helper(i+1,a,coins,tmp);

    

    tmp.push_back(coins[i]);

    helper(i,a-coins[i],coins,tmp);

    

    tmp.pop_back();

    

}

int change(int a, vector<int>& coins) {

    

    vector<int> tmp;

    helper(0,a,coins,tmp);

    return ans;

    

}

};

DP (1-D)

class Solution {

public:

int change(int amount, vector& coins) {

    int n=coins.size();

    

    if(n==0)

    {

        if(amount==0)

            return 1;

        else

            return 0;

    }

    

    vector<int> dp(amount+1,0);

    

    dp[0]=1;

    

    for(int i=0;i<n;i++)

    {

        for(int j=coins[i];j<=amount;j++)

        {

            dp[j]=dp[j]+dp[j-coins[i]];

        }

    }

     

    return dp[amount];
    }
};*/
    class Solution {

public:

    int count(int index, vector<int>& coins, vector<vector<int>> &dp, int amount) {

        

        if(amount == 0) return 1;

        if(index == 0) {

            if (amount % coins[0] == 0) return 1;

            else return 0;

        }

        if(dp[index][amount] != -1) return dp[index][amount];

        

        if(coins[index] > amount)

            return count(index - 1, coins, dp, amount);

        

        return dp[index][amount] = count(index - 1, coins, dp, amount) + 

                                            count(index, coins, dp, amount - coins[index]);

    }

    

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));

        return count(n - 1, coins, dp, amount);

    }

};