class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<int> a(m,-1);
        vector<int> b(n,-1);
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j]==0)
                    a[i]=0, b[j]=0;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(a[i]==0 or b[j]==0)
                    matrix[i][j]=0;
    }
};