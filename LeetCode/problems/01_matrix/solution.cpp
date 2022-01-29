class Solution {
    int xDir[4] = {0, 0, 1, -1};
    int yDir[4] = {1, -1, 0, 0};
    int N,M;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        N = mat.size(); M = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(N, vector<int>(M, 0));
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++) {
                int x = r + xDir[i], y = c + yDir[i];
                if(isValid(x,y) && !vis[x][y]) {
                    vis[x][y] = 1;
                    mat[x][y] = mat[r][c] + 1;
                    q.push({x,y});
                }
            }
        }
        
        return mat;
    }
    
    bool isValid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
};