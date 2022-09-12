class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int ans=0;
        sort(tokens.begin(), tokens.end());
        int i=0, j=tokens.size()-1;
        
        while(i<=j)
        {
            if(tokens[i]<=power)
            {
                power-=tokens[i];
                i++;
                ans++;
            }
            
            else
            {
                if((power+tokens[j])<tokens[i] or ans==0 or i==j)
                    break;
                
                power+=tokens[j];
                j--;
                ans--;
            }
        }
        return ans;
        
    }
};