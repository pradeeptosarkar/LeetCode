class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
     //dp[i] stores the largest digit that can be fromed with i as target
        vector<string> dp(target+1,"#");
        
        int len=cost.size();
        helper(cost,len,target,dp);
        return dp[target];
        
    }
    string helper(vector<int>& cost,int& len,int target,vector<string>& dp)
    {
        if(target==0)
            return "";
        //the current sub problem is already calculated
        if(dp[target]!="#")
            return dp[target];
        
        //not yet calculated
        dp[target]="0";
        string curr="";
        for(int i=len-1;i>=0;i--)
        {
            //use i if the cost is less than or equal to the target
            if(cost[i]<=target){
                curr.push_back(i+1+'0');
                string x=helper(cost,len,target-cost[i],dp);
                //if the return string is not zero 
                //it means we can build some largest number with the remaining target
                if(x!="0")
                {
                    
                    //we can form some number with the remaining target
                    curr.append(x);
                    int currLen=curr.length();
                    int tLen=dp[target].length();
                    //update if we got the largest number than dp[target]
                    if(tLen < currLen)
                        dp[target]=curr;
                    else if(tLen == currLen)
                        dp[target]=max(dp[target],curr);
                }
                curr="";
            }
                
        }
        //now dp[target] would be either 0 or some digit(if there is some answer) 
        return dp[target];   
    }
};