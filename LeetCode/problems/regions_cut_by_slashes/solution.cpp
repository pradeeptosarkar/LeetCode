class Solution {
public:
    int find(int x,vector<int> &par){
        if(x==par[x]){
            return x;
        }
        int t=find(par[x],par);
        par[x]=t;
        return t;
    }
    bool uni(int i,int j,vector<int> &par,vector<int> &rank){
        int lx=find(i,par);
        int ly=find(j,par);
        if(lx!=ly){
            if(rank[lx]>rank[ly]){
                par[ly]=lx;
            }else if(rank[lx]<rank[ly]){
                par[lx]=ly;
            }else{
                par[lx]=ly;
                rank[ly]++;
            }
            return false;
        }
        return true;
    }
    int regionsBySlashes(vector<string>& grid) {
        vector<int> par((grid.size()+1)*(grid.size()+1));
        vector<int> rank((grid.size()+1)*(grid.size()+1),1);
        for(int i=0;i<par.size();i++){
            par[i]=i;
        }
        for(int i=0;i<grid.size()+1;i++){
            for(int j=0;j<grid[0].size()+1;j++){
                if(i==0||j==0||i==grid.size()||j==grid[0].size()){
                    int cellno=i*(grid.size()+1)+j;
                    if(cellno!=0){
                        uni(0,cellno,par,rank);
                    }
                }
            }
        }
        int ans=1;
      for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='/'){
                    int x=i*(grid.size()+1)+j+1;
                    int y=(i+1)*(grid.size()+1)+j;
                    ans+=uni(x,y,par,rank);
                }else if(grid[i][j]=='\\'){
                         int x=i*(grid.size()+1)+j;
                    int y=(i+1)*(grid.size()+1)+j+1;
                    ans+=uni(x,y,par,rank);
                }
            }
      }
                         return ans;
        
    }
};