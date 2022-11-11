class Solution {
public:
    bool haveConflict(vector<string>& e1, vector<string>& e2) 
    {
        if(((e1[0]<=e2[0]) && (e2[0]<=e1[1])) || ((e2[0]<=e1[0]) && (e1[0]<=e2[1])))
          return true;
        
        return false;
    }
};