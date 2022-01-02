class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int num = 1,r1 =0,r2 = n-1,c1 =0,c2 = n-1;
        while(r1<=r2 && c1<=c2)
        {
            //For first row
            for(int i = c1;i<=c2;i++)
            {
                ans[r1][i] = num++;
            }
            //For last column
            for(int j =r1+1;j<=r2;j++)
            {
                ans[j][c2] = num++;
            }
            //For last row
            if(r1 != r2)
            {
                for(int i = c2-1;i>=c1;i--)
                {
                    ans[r2][i] = num++;
                }
            }
            //For first column
            if(c1 != c2)
            {
                for(int i = r2-1;i>r1;i--)
                {
                    ans[i][c1] = num++;
                }
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
};