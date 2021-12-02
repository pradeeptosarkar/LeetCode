class Solution {
public:
    int addDigits(int num) 
    {
        int ans;
        
        if(num==0)
            return 0;
        
        else
        {
            ans=num%9;
            
            if(ans!=0)
              return ans;
            
            else
                return 9;
        }
    }
};