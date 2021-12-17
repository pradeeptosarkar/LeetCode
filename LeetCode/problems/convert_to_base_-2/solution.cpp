class Solution {
public:
    string baseNeg2(int n) {
        string res = "";
        
        if(n == 0)
            return "0";
        
        while(n != 0){
            if(n % 2 == 0){
                res = "0" + res;
                n = (n / (-2));
            }
            else{
                res = "1" + res;
                n = (n - 1)/ -2;
            }
                       
        }
        return res;
    }
};