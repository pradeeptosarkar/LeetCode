class Solution {
public:
    
    // row and col child offset
    int rowchild[4] = {-1,1,0,0};
    int colchild[4] = {0,0,1,-1};
    
    // disjoint set parent track
    int mat[40001];
    
    // disjoint set size
    int mat_s[40001];
    
    // grid row and col size
    int row,col;
    
    // node count connected to top row
    int top_count;
    
    // track nodes of top row already taken
    bitset<201>top_nodes;
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        
        row = grid.size();
        col = grid[0].size();
        int n = hits.size();
        int total = row * col;
        top_count = 0;
        
        // reset all top row track bit
        for(int i=0;i<col;i++)top_nodes[i] = 0;
        
        // all node is parent to itself and has size 1
        for(int i=0;i<total;i++)mat[i]=-1,mat_s[i]=1;

        // create new grid of same size to perform union find operation
        vector<vector<int>>ngrid(row,vector<int>(col));
        ngrid = grid;
        
        // make all hits position 0 in the grid 
        for(int i=0;i<n;i++)ngrid[hits[i][0]][hits[i][1]] = 0;
        
        // result vector
        vector<int>res(n,0);
        
        // loop through the grid and perform union find for bricks node with neighbors
        // we assign min parent as the parent of max parent node only if they are not both in top row
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                if(ngrid[i][j])
                    unifyNeighbor(ngrid,i,j);   // Unify current node with brick neighbors 
            }
        }
        
        // number of node connected to top row after ith operation        
        int top_s = top_count;
        int nx,ny;
        
        // We move from right to left of hits vector and mark current hit pos as brick node
        // do union find over its neighbor and update top_count
        // diff between prev top_count and current top_count is the number of bricks which fallen
        // if given grid has no brick in hit position then nothing to fall and so we ignore the step 
        for(int i=n-1;i>=0;i--)
        {
            nx = hits[i][0];
            ny = hits[i][1];

            if(grid[nx][ny]==0)continue;
            else
            {
                // Unify current node with brick neighbors 
                unifyNeighbor(ngrid,nx,ny);

                ngrid[nx][ny] = 1;
                
                // fallen brick = current top_count - prev top_count - 1
                res[i] = max(0,top_count-top_s-1);
                top_s = top_count;
            }
        }
        
        return res;
    }
    
    // Unify current node with brick neighbors 
    void unifyNeighbor(vector<vector<int>>&ngrid, int x, int y)
    {
        int t,p,px,py;
        p = t = x * col + y;

        for(int k=0;k<4;k++)
        {
            px = x + rowchild[k];
            py = y + colchild[k];
            if(px>=0 && px<row && py>=0 && py<col && ngrid[px][py]==1)
            {
                int v = unify(px*col+py,t,true);
                if(v!=-1) t = v;
            }
        }

        // if current node is in top row and not yet taken 
        // then we update top_count and mark node as taken
        // this happens when current top row brick has no neighbor brick                 
        if(p<col && top_nodes[p]==0)top_count+=mat_s[p],top_nodes[p]=1;
    }
    
    
    // find the parent of the node and do path compression recursively
    // if node parent is -1 then node is parent itself
    int find(int t)
    {
        if((mat[t]<0 || t == mat[t]))return t;
        
        return mat[t] = find(mat[t]);        
    }
    
    // unify node t1 and t2 if they have diff parent or their both parents do not fall in top row
    // we assign min parent as parent of max parent node and update size of min parent node
    // if min parent node fall in top row then we update top_count 
    // if min parent node not already taken we directly add the size and mark it as taken
    // otherwise we have to deduct the prev min parent size from top_count and then update with new value
    int unify(int t1, int t2, bool flag =false)
    {
        int p1 = find(t1);
        int p2 = find(t2);
        
        // if same parent or both parent in top row then do not unify
        if(p1==p2 || (p1<col && p2<col)) return -1;        
        
        int parent = min(p1,p2);
        int child = max(p1,p2);
        mat[child] = parent;
        
        // parent in top row and already taken then deduct prev size from top_count
        if(parent<col && top_nodes[parent])top_count-=mat_s[parent];
        
        // update parent size with child size
        mat_s[parent]+=mat_s[child];  
        
        // parent in top row and so update top_count with latest parent size
        if(parent<col)top_count+=mat_s[parent],top_nodes[parent]=1;
                    
        return parent;
    }
    
};