class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int b=0;
        stack<int> stk;
        
        for(int a=0;a<pushed.size();a++)
        {
            stk.push(pushed[a]);
            while(!stk.empty() && popped[b]==stk.top())
            {
                stk.pop();
                b++;
            }
        }
        return stk.empty();
    }
};