class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = n-2;i>=0;i--){
            matrix[i][0] += min(matrix[i+1][0],matrix[i+1][1]);
            matrix[i][n-1] += min(matrix[i+1][n-1],matrix[i+1][n-2]);
            for(int j = 1;j<n-1;j++){
                matrix[i][j] += min(matrix[i+1][j],min(matrix[i+1][j-1],matrix[i+1][j+1]));
            }
        }
        int minEle = INT_MAX;
        for(int i=0;i<n;i++){
            minEle = min(matrix[0][i],minEle);
        }
        return minEle;
    }
};