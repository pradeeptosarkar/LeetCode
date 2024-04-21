class Solution {
public:
    void findingPath(int i,int dest,vector<vector<int>>& edges,unordered_map<int,vector<int>>&adj,vector<bool>&visted,bool &path){
        visted[i]=true;
        for(auto nbr:adj[i]){
            if(nbr==dest){
                path=true;
                return;
            }
            if(visted[nbr]==false)
                findingPath(nbr,dest,edges,adj,visted,path);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        unordered_map<int,vector<int>>adj;
        vector<bool>visted(n,false);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        bool path=false;
        for(int i=0;i<n;i++){
            path=false;
            if(i==source && visted[i]==false)
                findingPath(source,destination,edges,adj,visted,path);
            if(path==true){
                return true;
            }
        }
        return path;
    }
};
