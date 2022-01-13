class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n=temperatures.size();
        stack<int> temp;
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--)
        {
           while(!temp.empty() && temperatures[temp.top()]<=temperatures[i])
           {
               temp.pop();
           }
           if(!temp.empty())
               res[i]=temp.top()-i;
                     
           temp.push(i);
        }
       
        return res;
    }
};