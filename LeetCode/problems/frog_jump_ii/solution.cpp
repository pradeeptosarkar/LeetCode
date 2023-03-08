class Solution {
public:
    int maxJump(vector<int>& stones) 
    {
        int ans=stones[1];
        
        for(int i=1;i<stones.size()-1;i++)
            ans=max(ans, stones[i+1]-stones[i-1]);
        return ans;        
    }
};