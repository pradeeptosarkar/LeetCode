class Solution {
public:
    int climbStairs(int n) 
    {
        /*if (n == 0) 
            return 0;
        if (n == 1) 
            return 1;
        if (n == 2) 
            return 2;
        */
        
        //int* steps = new int[n + 1];
        
        int steps[46];
        steps[0] = 0;
        steps[1] = 1;
        steps[2] = 2;
        
        if(n==0 || n==1 || n==2)
            return n;
        
        for (int i=3; i<=n; i++) 
        {
            steps[i] = steps[i - 1] + steps[i - 2];
        }
        return steps[n];
    }
};