class Solution {
public:
    vector<int> beautifulArray(int N) {
        
        // initial beatiful array
        vector<int>res={1};
        
        // loop until all N values are generated
        while(res.size()<N)
        {
            vector<int>temp;
            
            // push all odd values generated from current beautiful array
            for(auto &x : res)if(x*2-1 <=N)temp.push_back(x*2-1);
            
            // push all even values generated from current beautiful array
            for(auto &x : res)if(x*2 <=N)temp.push_back(x*2);
            
            // swap result
            res=temp;
        }
        
        return res;
    }
};