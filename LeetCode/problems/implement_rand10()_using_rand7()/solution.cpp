//::Pradeepto Sarkar LC470:://

class Solution {
public:
    int rand10() 
    {
        int row, col, idx;
    
        do
        {
            row=rand7();
            col=rand7();
            idx=col+(row-1)*7;
        } while(idx>40);
        
        return idx%10+1;
    }
};