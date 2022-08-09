class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(auto c:t) 
            m[c]++;
        int start=0,end=0,count=t.size(),head=0,mini=INT_MAX;
        while(end<s.size()){
            if(m[s[end]]>0) count--;
            m[s[end]]--;
            end++;
            while(count==0){
                if(end-start<mini){
                    head=start;
                    mini=end-start;
                }
                m[s[start]]++;
                if(m[s[start]]>0) count++;
                start++;
            }
        }
        return mini==INT_MAX?"":s.substr(head,mini);
    }
};