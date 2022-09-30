class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> ans;
        
        int pos=0; 
        int currDist=buildings[0][0]; 
        
        while (!pq.empty() or pos<buildings.size()) 
        {
             
            if (pq.empty()) 
            {              
                int nextLeft=buildings[pos][0];
                
                while(pos<buildings.size() and buildings[pos][0]==nextLeft) 
                {
                    pq.push({buildings[pos][2], buildings[pos][1]});
                    pos++;
                }
                
                
                ans.push_back({nextLeft, pq.top().first});
                currDist=nextLeft;
                continue;
            }
            
            
            int currHeight=pq.top().first;
            
            if (pos<buildings.size()) 
            {                 
                int nextLeft=buildings[pos][0];
                int endOfBlock=pq.top().second;

                
                if (nextLeft<=endOfBlock) 
                {
                    
                    while (pos<buildings.size() and buildings[pos][0]==nextLeft) 
                    {
                        pq.push({buildings[pos][2], buildings[pos][1]});
                        pos++;
                    }
                    currDist=nextLeft; 
                }
                else 
                { 
                    currDist=endOfBlock;
                    
                    while (!pq.empty() and pq.top().second<=currDist)
                        pq.pop();
                }
            }
            
            else 
            {
                
                currDist=pq.top().second;
                
                while (!pq.empty() and pq.top().second<=currDist)
                {
                    pq.pop();
                }
            }
            
            if (pq.empty()) 
            {
                ans.push_back({currDist, 0});
                continue;
            } 
             
            if (pq.top().first!=currHeight) 
                ans.push_back({currDist, pq.top().first});
            
        }
        return ans;
    }
};