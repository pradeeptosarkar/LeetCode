class Solution {
public:
   bool checkPartitioning(string s) {
        int len=s.length();
        
        if(len==3)
            return true;
        
        vector<vector<bool>> isPal = vector<vector<bool>>(len, vector<bool>(len, false));
       
        for(int i=0; i<len; i++)
            isPal[i][i]=true;
        
        for(int i=0; i+1<len; i++)
            if(s[i+1]==s[i])
                isPal[i][i+1]=true;
        
        for(int k=2; k<len; k++)       //making the isPal table for palindrome checking  in future
            for(int i=0; i+k<len; i++)    // isPal[i][j] = true if string from i to j is palindrome.
                if(s[i+k]==s[i] && isPal[i+1][i+k-1]==true)
                    isPal[i][i+k]=true;
            
        for(int i=0; i<len; i++){
            if(!isPal[0][i])
                continue;
            for(int j=len-1; j>i; j--){
                if(!isPal[j][len-1])
                    continue;
                if(isPal[i+1][j-1])
                    return true;
                else 
                    continue;
            } 
        }
            
        return false;    
    }
};