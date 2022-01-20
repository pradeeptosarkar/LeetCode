class Solution {
public:
    vector<vector<int>> prefixMatrix;
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        for(int i=0;i<matrix.size();i++){
            vector<int> temp;
            for(int j=0;j<matrix[i].size();j++){
                temp.push_back(0);
            }
            prefixMatrix.push_back(temp);
        }
        prefixMatrix[0][0] = matrix[0][0];
        for(int i=1;i<matrix[0].size();i++){
            prefixMatrix[0][i] = prefixMatrix[0][i-1] + matrix[0][i];
        }
        for(int i=1;i<matrix.size();i++){
            prefixMatrix[i][0] = prefixMatrix[i-1][0] + matrix[i][0];
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                prefixMatrix[i][j] = matrix[i][j] + prefixMatrix[i][j-1] + prefixMatrix[i-1][j] - prefixMatrix[i-1][j-1];
            }
        }
        int m = matrix.size();
        
        for(int i=0;i<matrix.size();i++){
            int n = matrix[i].size();
            for(int j=0;j<matrix[i].size();j++){
                int row1 = max(i-k,0);
                int col1 = max(j-k,0);
                int row2 = min(i+k,m-1);
                int col2 = min(j+k,n-1);
                
                matrix[i][j] = sumRegion(row1, col1, row2, col2);
            }
        }
        return matrix;
        
    }
    
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0){
            return prefixMatrix[row2][col2];
        }
        else if(row1 == 0){
            return prefixMatrix[row2][col2] - prefixMatrix[row2][col1-1];
        }
        else if(col1 == 0){
            return prefixMatrix[row2][col2] - prefixMatrix[row1-1][col2];
        }
        
        
        return prefixMatrix[row2][col2] - prefixMatrix[row2][col1-1] -prefixMatrix[row1-1][col2] + prefixMatrix[row1-1][col1-1];
    }
};