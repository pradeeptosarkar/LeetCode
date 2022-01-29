class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int ans=INT_MIN, areawithtop=0, top=0, i=0, n=heights.size();
        stack<int> s;
        
        while(i<n)
        {
            if(s.empty() or heights[s.top()]<=heights[i])
                s.push(i++);
            
            else
            {
                top=s.top();
                s.pop();
                areawithtop=heights[top]*(s.empty()?i:i-s.top()-1);
                ans=max(ans, areawithtop);
            }
        }
        
        while(!s.empty())
        {
            top=s.top();
            s.pop();
            areawithtop=heights[top]*(s.empty()?i:i-s.top()-1);
            ans=max(ans, areawithtop);
        }
        return ans;
    }
};