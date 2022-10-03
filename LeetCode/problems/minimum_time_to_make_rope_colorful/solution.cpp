class Solution {
public:
    int minCost(string s, vector<int>& cost) 
    {
      
        int ans=0;

        int total=0,sum=0;

        for(auto x:cost) total += x;

        for(int i=0 ; i<s.size() ; i++)

        {

            int temp=s[i],maxval=0;

            while(s[i]==temp)

            {

                maxval = max(maxval,cost[i]);

                i++;

            }

            sum += maxval;

            i--;    

        }

        return total-sum;  
    }
};