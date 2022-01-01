class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        
        //first fill the cols whose colsum[i]==2 
        
        vector<vector<int>> empty;
        int len=colsum.size();
        vector<vector<int>> res(2,vector<int>(len,0));
        
        //the count of cols whose colsum[i]==1
        int ones=0;
        for(int i=0;i<len;i++)
        {
            if(colsum[i]==1)
                ones++;
            else if(colsum[i]==2)
            {
                if(upper==0 || lower==0)
                    return empty;
                res[0][i]=res[1][i]=1;
                upper--;
                lower--;
            }
        }
		// we cant fill the cols whose colsum is 1
        if(ones!=(lower+upper))
            return empty;
        
        for(int i=0;i<len;i++)
        {
            if(colsum[i]==1)
            {
                if(upper)
                {   
				    //fill the first row
                    res[0][i]=1;
                    upper--;
                }
                else{
				//fill the second row
                    res[1][i]=1;
                    lower--;
                }
            }
        }
        return res;
    }
};