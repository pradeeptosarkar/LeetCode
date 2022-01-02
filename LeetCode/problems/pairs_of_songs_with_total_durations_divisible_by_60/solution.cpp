class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
    int n = time.size();
        for(int i=0; i<n; ++i) time[i] = time[i]%60;
        
        unordered_map<int,int> map;
        
        int cnt = 0;
        for(int i=0; i<n; ++i){
            int m = time[i];
            int f = 60 - m;
            if(f == 60){
                if(map.find(0) != map.end()) cnt+=map[0];
            }else{
                if(map.find(f) != map.end()) cnt+=map[f];
            }
            map[time[i]]++;
        }
		
        return cnt;    
    }
};