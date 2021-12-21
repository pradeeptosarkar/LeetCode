class Solution {
public:
    bool hasAlternatingBits(int n) {
    int flag=-1,flag1=-1;
        while(n){
           flag=n&1;
           if(flag!=-1 && flag1!=-1){
               if(flag==flag1) return false;
           } 
            flag1=flag;
            n=n>>1;
        }
        return true;    
    }
};