class Solution {
public:
    
    bool validUtf8(vector<int>& data) 
    { 
        int i=0;
        int n= data.size();
        
        while (i<n)
        {
            if (data[i] >=248) 
                return false;
            
            if ( data[i]>=240 &&data[i]<=247 ) 
            {
                if (i+3>n) 
                    return false;
                if ((data[i+1] <128 || data[i+1] >191)|| (data[i+2] <128 || data[i+2] >191)||(data[i+3] <128 || data[i+3] >191)) 
                    return false;
              i+=4;  
            }
            
            else if ( data[i]>=224 &&data[i]<=239 ) 
            {

                if (i+2>n) return false ;
                if ((data[i+1] <128 || data[i+1] >191)||(data[i+2] <128 || data[i+2] >191)) return false;

                i+=3;  
            }
            
            else if (( data[i]>=192 &&data[i]<=233 )) 
            {
                if (i+1>n) 
                    return false;
                if ((data[i+1] <128  || data[i+1] >191)) 
                    return false;
                
                i+=2;
            }
            
           else if ( data[i]<=127 )            
              i+=1;  
           
           else 
               return false;
        
        }
        return true;
    }
};