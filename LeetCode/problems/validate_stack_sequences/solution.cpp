class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> stk;
        int i=0,j=0;
        
        for(i;i<pushed.size();i++)
        {
            stk.push(pushed[i]);
            
            while(!stk.empty() and stk.top()==popped[j])
            {
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
};