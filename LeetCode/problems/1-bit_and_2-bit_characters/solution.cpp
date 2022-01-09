class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        bool result;
    for(int i=0 ; i<bits.size() ; ++i) {
        if(bits[i] != 0) {
            result = false;
            ++i;
        }
        else result = true;
    }
    return result;
    }
};