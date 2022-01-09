class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
      
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        
        for(int i=0;i<=r-3;i++){
            
            for(int j=0;j<=c-3;j++){
            
               bool b=1;
                int arr[10]={};
                
                for(int rr=i;rr<i+3;rr++){
                    for(int cc=j;cc<j+3;cc++){
                        if(grid[rr][cc]>9 or grid[rr][cc]<1){
                            b=0;
                            break;
                        }
                        else
                            {
                                if(arr[grid[rr][cc]]==0)
                                    arr[grid[rr][cc]]=1;
                                else{
                                    b=0;break;
                                }
                             }
                    }
                    if(!b) break;
                }
                if(b){
                    bool bb=1;
                    int prev=INT_MIN;
                    for(int rr=i;rr<i+3;rr++){
                        int sm=grid[rr][j]+grid[rr][j+1]+grid[rr][j+2];
                        if(prev==INT_MIN) prev=sm;
                        else if(prev!=sm){
                            bb=0;
                            goto last;
                        }
                    }
                    
                    for(int cc=j;cc<j+3;cc++){
                        int sm=grid[i][cc]+grid[i+1][cc]+grid[i+2][cc];
                        if(prev!=sm){
                            bb=0;goto last;
                        }
                    }
                    if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=prev)
                        bb=0;
                    if(grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]!=prev)
                        bb=0;
                    last:
                    if(bb)
                        ans++;
                }
            }
        }
        return ans;
    }
};