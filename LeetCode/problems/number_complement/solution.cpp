class Solution {
public:
    int findComplement(int num) 
    {
        int one =1;
int tem=num;
while(tem != 0)
{
num^=one;
one<<=1;
tem>>=1;
}
return num;
    }
};