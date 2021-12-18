class Solution {
public:
    char findKthBit(int n, int k) {
       if(n==1 && k==1)
         return '0';
      
      int lPrev=pow(2,n-1)-1; //length of Sn-1 (just previous string)
      
      if(k<=lPrev){
        return findKthBit(n-1,k); 
      }
      else{
        if(k==lPrev+1)
          return '1';    //Extra added char '1' after copying Sn-1
        else
        {
          k=k-(lPrev+1);  
          char c=findKthBit(n-1,lPrev-k+1);
          if(c=='0')
            return '1';
          else
            return '0';
        }
      }
         
      return '0';
    }
};