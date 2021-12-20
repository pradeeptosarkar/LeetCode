class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        
        unordered_map<char, int> mp1, mp2;
        for(int i=0; i<s1.size(); i++){
            mp1[s1[i]]++;
        }
        for(int i=0; i<s1.size()-1; i++){
            mp2[s2[i]]++;
        }
        int i=0, j=s1.size()-1, flag = true;
        while(j < s2.size()){
            flag = true; 
            mp2[s2[j++]]++;
            
            if(j-i == s1.size()){
                for(auto it=mp1.begin(); it!=mp1.end(); it++){
                    if(mp2[it->first] != mp1[it->first]){
                        flag =  false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
            mp2[s2[i++]]--;
        }
        return false;
    }
};