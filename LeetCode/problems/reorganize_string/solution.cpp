class Solution {
public:
    string reorganizeString(string s) 
    {
        string ans="";
        vector<int> v(26,0);
        
        for(auto c:s)
            v[c-'a']+=1;
        
        priority_queue<vector<int>> pq;
        
        for(int i=0;i<26;i++)
            if(v[i]>0)
                pq.push({v[i], i+'a'});
        
        while(!pq.empty())
        {
            auto first=pq.top();
            pq.pop();
            
            if(ans.size()==0 or ans.back()!=first[1])
            {
                ans+=char(first[1]);
                
                if(first[0]>1)
                    pq.push({--first[0], first[1]});
            }
            
            else
            {
                if(pq.empty())
                    return "";
                
                auto second=pq.top();
                pq.pop();
                
                ans+=second[1];
                
                if(second[0]>1)
                    pq.push({--second[0], second[1]});
                
                pq.push(first);
            }
        }
        
        return ans;
    }
};