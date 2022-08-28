class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        unordered_map<int,priority_queue<int>> mp;
        
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                mp[i-j].push(mat[i][j]*-1);
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                mat[i][j]=(mp[i-j].top())*-1;
                mp[i-j].pop();
            }
        }
        return mat;
        
    }
};