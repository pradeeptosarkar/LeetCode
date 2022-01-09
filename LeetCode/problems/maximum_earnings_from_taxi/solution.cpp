class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    // update cost in vector (as given tip + end -start)
        
      for(auto & x:rides)
      x[2]+=x[1]-x[0];
        
   // sort by  start time in descending order
        
     sort(rides.begin(),rides.end(),greater<vector<int>>());
        
      map<long long int,long long int>dp;
        long long int maxP=0;
        
        for(auto ride:rides)
        {
        // check for given ride endtime check if there is any time greater than equal to present in map -> ex:- [13,18,1] already traversed when we check for ride [10,12,3] then we will get [13,18,1] in map similary we will check for possibilities
          auto j= dp.lower_bound(ride[1]); 
    // in case there is no greater start time than our current endtime exists in map iterator will point to end in this case we will add zero profit else update with last ride profit
          long long int v= (j==dp.end())? 0: j->second;
          maxP=max(maxP,ride[2]+v);
    // update startime with max profit with rides uptill now it will help in next ride to decide whether can take the ride or not.
         dp[ride[0]]=maxP;
            
        }
        return maxP; 
    }
};