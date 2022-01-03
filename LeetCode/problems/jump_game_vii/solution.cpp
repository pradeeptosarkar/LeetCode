class Solution {
public:
    int canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int n=s.length();
        if(s[n-1]=='1')
        return false;
        q.push(0);
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
            while(!q.empty()&&q.front()+maxJump<i)
            {
                q.pop();
            }
                if(q.empty())
                return false;
                int prev=q.front();
                if(prev+maxJump>=i&&prev+minJump<=i)
                {
                    q.push(i);
                    if(i==n-1)
                    return true;
                }
            }
        }
        return false;
    }
};