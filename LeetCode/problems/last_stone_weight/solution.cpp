class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> q;
        for(auto i:stones)
            q.push(i);
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            
            if(a==b)
                continue;
            else
            {
                q.push(abs(a-b));
            }
        }
        if(q.empty())
            return 0;
        
        return q.top();
    }
};