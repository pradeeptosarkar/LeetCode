class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, k = mat.size(), mid, odd = 1;
        mid = k/2;
        if (k % 2 == 0) 
            odd = 0;
        k--;
        switch (odd) {
            case 1:
                for (int i = 0; i <= mid; i++) {
                    if (i == mid) {
                        sum += mat[i][i];
                    }
                    else {
                        sum += mat[i][i] + mat[i][k];
                        sum += mat[k][i] + mat[k][k];
                        k--;
                    }
                }
                break;
            case 0:
                for (int i = 0; i < mid; i++) {
                    if (i == mid - 1) {
                        sum += mat[mid - 1][mid - 1] + mat[mid - 1][mid];
                        sum += mat[mid][mid - 1] + mat[mid][mid];
                    }
                    else {
                        sum += mat[i][i] + mat[i][k];
                        sum += mat[k][i] + mat[k][k];
                        k--;
                    }
                }
                break;
        }
        return sum;
    }
};