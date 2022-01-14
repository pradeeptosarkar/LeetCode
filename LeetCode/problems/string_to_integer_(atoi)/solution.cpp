class Solution {
public:
  int myAtoi(string s) {
        long l=s.length(),num=0;
        int i=0,j=1;
        for(i=0;i<l;i++)
        {
            if(s[i]!=' ')break;
        }
        if(s[i]=='-'){j=-1;i++;}
        else if(s[i]=='+')i++;
        for(;i<l;i++)
        {
            if(s[i]>='0'&&s[i]<='9')  
            {
                num = num*10+(int)(s[i]-'0');
                 if(j*num<INT32_MIN)
        {
            return INT32_MIN;
        }
        if(j*num>INT32_MAX)
        {
            return INT32_MAX;
        }
            }else{
                break;
            }
        }
        num*=j;
        if(num<INT32_MIN)
        {
            return INT32_MIN;
        }
        if(num>INT32_MAX)
        {
            return INT32_MAX;
        }
        return num;
    }
};