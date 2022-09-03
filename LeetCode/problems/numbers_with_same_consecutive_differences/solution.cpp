class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<int> ans={1,2,3,4,5,6,7,8,9};
        
        for(int i=2;i<=n;i++)
        {
            vector<int> temp;
            
            for(auto t:ans)
            {
                int tt=t%10;
                
                if(tt+k<10)
                    temp.push_back((t*10)+tt+k);
                if(k>0 and tt-k>=0)
                    temp.push_back((t*10)+tt-k);
            }
            ans=temp;
        }
        return ans;
    }
};