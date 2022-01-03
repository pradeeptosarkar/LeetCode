class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
      int totalJudges = 0;
    
    vector<map<int,int>> nodes(n+1);
    for(auto i: trust){
        nodes[i[0]][i[1]] = 1;
    }
    
    vector<int> potentialJudge(n+1,0);
    for(int i = 1; i<nodes.size(); ++i){
        if(nodes[i].size() == 0){
            potentialJudge[i] = 1;
            totalJudges++;
        }
    }
    
    for(int pj=1;pj<nodes.size();++pj){
        
        if(potentialJudge[pj] == 0) continue;
        
        for(int i=1;i<nodes.size();++i){
            
            if(i!=pj && nodes[i][pj] == 0){
                potentialJudge[pj] = 0;
                totalJudges--;
                break;
            }
            
        }
    }
    
    if(totalJudges == 1){
        for(int pj=1;pj<nodes.size();++pj){
        
            if(potentialJudge[pj]) return pj;

        }
    }
    
    return -1;  
    }
};