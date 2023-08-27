class Solution {
public:
    long long minimumPossibleSum(int n, int target) 
    {
        if(n==1)
            return n;
        
        long long ans=0;
        int counter=1;
        set<int> s;
        
        while(s.size()<n)
        {
            if(s.find(target-counter)==s.end())
            {
                s.insert(counter),
                ans+=counter;
            }
            
            counter++;
        }
        
        return ans;
    }
};