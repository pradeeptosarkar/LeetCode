class Solution {
public:
    int furthestDistanceFromOrigin(string moves) 
    {
        int ans=0;
        int blanks=0;
        
        for(auto i:moves)
        {
            if(i=='_') blanks++;
            
            else 
                i=='R' ? ans+=1 : ans-=1;
        }
        
        return abs(ans)+blanks;        
    }
};