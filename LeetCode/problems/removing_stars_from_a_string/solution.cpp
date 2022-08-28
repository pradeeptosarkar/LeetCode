class Solution {
public:
    string removeStars(string s) 
    {
        string ans="";
        stack<int> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='*')
                st.push(s[i]);
            else
                st.pop();
        }
        if(st.empty())
            return ans;
        else
        {
            while(!st.empty())
            {
                ans+=st.top();
                st.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};