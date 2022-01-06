class Solution {
public:
    
    vector<vector<int>>dp_change ;
    vector<vector<int>>dp_partion ;
    
    int min_change( string& s, int start , int end)
    {
        if( dp_change[start][end] != -1) return dp_change[start][end] ;
       
        int not_same = 0 ;
        int i= start, j = end ;
       
        while( i< j)
        {
            if( s[i++] != s[j--] ) not_same++ ;
        }
        
        return dp_change[start][end] = not_same ;
    }
    
    
    int partion_fxn( string& s, int start , int rem_partion)
    {
          if( dp_partion[start][rem_partion] != -1) return dp_partion[start][rem_partion] ;
        
        if( start == s.size() ) return 1e9 ;
        
        if( rem_partion ==0 ) return min_change( s, start, s.size()-1 ) ;
        
        int ans = 1e9 ;
        
        for( int i = start ; i<s.size() ; i++)
        {
            int no_of_change = min_change( s, start, i) ; 
            
            ans = min( ans , no_of_change + partion_fxn( s, i+ 1, rem_partion-1 ) ) ;
        }
        
        return dp_partion[start][rem_partion] = ans ;
    }
    
    
    int palindromePartition(string s, int k)
    {
        dp_change.resize( s.size()+ 1, vector<int>(s.size()+ 1, -1) ); 
        dp_partion.resize( s.size()+ 1, vector<int>(k , -1) ); 
        
        
        return partion_fxn( s, 0 , k-1 ) ;
    }
};