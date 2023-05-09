class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int top=0; 
        int left=0;
        int bottom=matrix.size();
        int right=matrix[0].size();
        int size=bottom*right;
        bottom-=1;
        right-=1;
        vector<int> ans;
        int k=1;
        
        while(k<=size)
        {
            for(int i=left;i<=right && k<=size; i++,k++)
                ans.push_back(matrix[top][i]);
            
            top++;
            
            for(int i=top;i<=bottom && k<=size; i++,k++)
                ans.push_back(matrix[i][right]);
            
            right--;
            
            for(int i=right;i>=left && k<=size; i--,k++)
                ans.push_back(matrix[bottom][i]);
            
            bottom--;
            
            for(int i=bottom;i>=top && k<=size; i--,k++)
                ans.push_back(matrix[i][left]);
            
            left++;
        }
        
        return ans;
    }
};