class Solution {
public:
    int convertTime(string current, string correct) 
    {
        int current_min=0, correct_min=0;
        int ans=0;
        
        current_min=(current[0]*600)+(current[1]*60)+(current[3]*10)+(current[4]);
        correct_min=(correct[0]*600)+(correct[1]*60)+(correct[3]*10)+(correct[4]);
        
        int diff=correct_min-current_min;
        
        while(diff>0)
        {
            if(diff>=60)
                ans+=diff/60, diff%=60;
        
            else if(diff>=15)
                ans+=diff/15, diff%=15;
            
            else if(diff>=5)
                ans+=diff/5, diff%=5;
            
            else
                ans+=diff, diff=0;
        }
        return ans;
    
            
    }
};