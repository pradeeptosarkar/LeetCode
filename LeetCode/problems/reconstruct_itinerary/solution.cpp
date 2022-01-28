class Solution {
public:
    
    map<string, priority_queue<string, vector<string>, greater<string>>> Map;
    vector<string> ans;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        for(int i=0;i<tickets.size();i++) 
        {
            priority_queue<string, vector<string>, greater<string>> Queue;
            if(Map.find(tickets[i][0])==Map.end()) 
            {
                Map[tickets[i][0]]=Queue;  
            }  
            Map[tickets[i][0]].push(tickets[i][1]);
        }
        dfs("JFK");
        return ans;
    }
    
    void dfs(string str) 
    {    
        if(!Map[str].empty()) 
        {
            string next;
            while(!Map[str].empty()) 
            {
                next=Map[str].top();
                Map[str].pop();
                dfs(next);   
            }     
        }
        ans.insert(ans.begin(),str);
    }   
};