//::Pradeepto Sarkar LC1094:://

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curr=0;
        int increase[1001]={0};
        for(int i=0;i<trips.size();i++) 
        { 
            increase[trips[i][1]]+=trips[i][0];
            increase[trips[i][2]]-=trips[i][0];
        }
        for(int i=0;i<=1000;i++) 
        { 
            curr+=increase[i];
            if(curr>capacity)
                return false;
        }
        return true;
    }
};