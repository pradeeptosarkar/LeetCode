class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int maxi=*max_element(candies.begin(),candies.end());
        vector<bool> ans(candies.size(),0);
        for(int i=0;i<candies.size();i++)
            if(candies[i]+extraCandies>=maxi)
                ans[i]=1;
        return ans;                
    }
};