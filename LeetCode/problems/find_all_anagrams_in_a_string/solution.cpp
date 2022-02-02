class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int plen=p.size(), slen=s.size();
        
        if(plen>slen)
            return {};
        
        vector<int> pfreq(26,0), sfreq(26,0), soln;
        
        for(int i=0;i<plen;i++)
        {
            pfreq[p[i]-'a']++;
            sfreq[s[i]-'a']++;
        }
        
        if(pfreq==sfreq)
            soln.push_back(0);
        
        for(int i=1;i<slen-plen+1;i++)
        {
            sfreq[s[i-1]-'a']--;
            sfreq[s[i+plen-1]-'a']++;
            if(sfreq==pfreq)
                soln.push_back(i);
        }
        return soln;
        
    }
};