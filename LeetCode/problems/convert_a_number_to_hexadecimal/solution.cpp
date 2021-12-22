class Solution {
public:
    string toHex(int num) 
    {
        if(num==0) return "0";
        string ans="";
        if(num>0)
        {
            while(num)
            {
                int temp = num%16;
                num = num/16;
                if(temp>=10)
                {
                    ans = (char)('a'+temp-10) + ans;
                }
                else
                {
                    ans = (char)('0'+temp) + ans;
                }
            }
        }
        else
        {
            u_int n = num;
            while(n)
            {
                int temp = n%16;
                n = n/16;
                if(temp>=10)
                {
                    ans = (char)('a'+temp-10) + ans;
                }
                else
                {
                    ans = (char)('0'+temp) + ans;
                }
            }
        }
        return ans;
    }
};