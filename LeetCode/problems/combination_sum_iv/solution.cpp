class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       int n= nums.size();

    vector<unsigned long long> dp(target+1,0);

    dp[0]=1; //no. of ways to make target=0 is 1( dont take anything)

    

    // we are basically doing a bottom up dp 

    // becoz for our target, we need sum of  dp[target- ist_val] + dp[target- 2nd_val]+.........and so on...

    // we keep on building from bottom and for a particular target , we already have the lower_target dps ready

    // ofc our target (i) should be greater than current array element.... (curr_array_val(num) <= curr_target(i) )

    for( int i=1; i<= target; i++){

        for( auto num: nums){

            if( num<= i){

                dp[i]+= dp[i- num];

            }

        }

    }

    //return no. of ways to make target using the given values

    return dp[target]; 
    }
};