class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        int n=s.length();
        vector<int> count(n,1);
        stack<int> stk;
        
        stk.push(0);
        
        for(int i=1;i<n;i++)
        {
            if(!stk.empty())
                if(s[stk.top()]==s[i])
                    count[i]=count[stk.top()]+1;
            
            stk.push(i);
            
            if(count[stk.top()]==k)
                for(int j=0;j<k;j++)
                    stk.pop();
                
        }
        
        string ans;
        
        while(!stk.empty())
        {
            ans+=s[stk.top()];
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};