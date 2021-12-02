class Solution {
public:
    bool isHappy(int n) 
    {
        int temp=0;
        set<int> visited;
        
        while(true)
        {
            temp=0;
            while(n>0)
            {
                temp+=pow((n%10),2);
                n/=10;
            }
            n=temp;
            
            if(n==1)
                break;
            
            else if(visited.find(n)!=visited.end())
                return false;
            
            visited.insert(n);
            
        }
        return true;
        
    }
};