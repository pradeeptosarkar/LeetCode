class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        if(strs.size()==1)
            return 0;
        
        vector<bool> indices(1001, false);
        
        for(int i=1;i<strs.size();i++)
        {
            for(int j=0;j<strs[0].length();j++)
                if(strs[i][j]<strs[i-1][j])
                    indices[j] = true;
            
        }
        return count_if(indices.begin(), indices.end(), [](bool x){ return x == true; });
    }
};