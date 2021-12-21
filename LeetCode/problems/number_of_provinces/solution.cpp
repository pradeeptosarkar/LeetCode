class DisjointSet
{
   public:
   unordered_map<int,int> parent;
   unordered_map<int,int> rank;
    
   void makeSet(int n)
   {
       for(int i=0;i<n;i++)
       {
           parent[i]=i;
           rank[i]=1;
       }
   }
   int find(int n)
   {
       if(parent[n]==n)
           return n;
       return parent[n]=find(parent[n]);
   }
   int Union(int x,int y)
   {
       int a =find(x);
       int b =find(y);
       
       if(a==b)
           return 0;
       else if(rank[a]<rank[b])
           parent[a]=b;
       else if(rank[b]<rank[a])
            parent[b]=a;
       else
       {
           parent[b]=a;
           rank[a]++;
       }
       return 1;
           
   }
   
};
class Solution {
public:

	//DFS
    void dfs(int i,vector<vector<int>>&isc,vector<int> &visited)
    {
        visited[i]=1;
        int j=0;
        while(j<isc.size())
        {
            if(visited[j]==false&&(isc[i][j]==1))
                dfs(j,isc,visited);
            j++;
        }
    }
	
	//BFS
    void bfs(int i,vector<vector<int>>&isc,vector<int> &visited)
    {
        queue<int> q;
        q.push(i);
        while(q.size()>0)
        {
            int top =q.front(); q.pop();
            if(!visited[top])
                visited[top]=true;
            
            int j=0;
            while(j<isc.size())
            {
                if(visited[j]==false&&(isc[top][j]==1))
                    q.push(j);
                j++;
            }
            
        }
    }
	
//     int findCircleNum(vector<vector<int>>& isc) {
//         int n =isc.size();
//         int count=0;
//         vector<int> visited(n,0);
//         for(int i=0;i<n;i++)
//         {
//             if(visited[i]==0)
//             {
//                 // dfs(i,isc,visited);
//                 bfs(i,isc,visited);
//                 count++;
//             }
//         }
//         return count;
//     }
    
//DSU 1
//      int findCircleNum(vector<vector<int>>& isc) {
//         int n =isc.size();
//         int count=0;
//         DisjointSet dsu =DisjointSet();
//         dsu.makeSet(n);
         
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(isc[i][j])
//                     dsu.Union(i,j);
//             }
//         }
//         for(auto e : dsu.parent)
//         {
//             if(e.second==e.first)
//                 count++;
//         }
//         return count;
//     }
    
	    
//DSU 2
     int findCircleNum(vector<vector<int>>& isc) {
        int n =isc.size();
        int count=n;
        DisjointSet dsu =DisjointSet();
        dsu.makeSet(n);
         
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isc[i][j])
                    count-=dsu.Union(i,j);
            }
        }
        return count;
    }
};