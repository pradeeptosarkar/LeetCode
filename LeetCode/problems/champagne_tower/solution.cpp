class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
         double matrix[103][103]={0};
        matrix[0][0]=poured;
        int i,j;
        for( i=0;i<102;i++)
        {
            for( j=0;j<=i;j++)
            {
                if(matrix[i][j]>1.0)
                {
                    double remaining=matrix[i][j]-1.0;
                    matrix[i][j]=1.0;
                    matrix[i+1][j]+=remaining/2.0;
                    matrix[i+1][j+1]+=remaining/2.0;
                }
            }
        }
        return matrix[query_row][query_glass];
        
    }
};