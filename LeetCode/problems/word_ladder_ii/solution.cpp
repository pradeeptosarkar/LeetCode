class Solution {
public:
    vector<vector<string>> findLadders(string start,string end,vector<string>& word)
    {
        queue<vector<string>>q;
        unordered_set<string>st(word.begin(),word.end());
        q.push({start});
        unordered_set<string>vis;
        vector<vector<string>>ans;
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                auto path=q.front();
                q.pop();
                string s=path.back();
                for(int i=0;i<s.size();i++)
                {
                    char ch=s[i];
                    for(int j=0;j<26;j++)
                    {
                        s[i]=char(j+'a');
                        if(s[i]!=ch)
                        {
                            if(st.find(s)!=st.end())
                            {
                                vis.insert(s);
                                auto new_path=path;
                                new_path.push_back(s);
                                if(s==end)
                                {
                                    ans.push_back(new_path);
                                }
                                else
                                {
                                    q.push(new_path);
                                }
                             }
                        }
                    }
                    s[i]=ch;
                }
            }
            for(auto &it:vis)
                {
                    st.erase(it);
                }
        }
        return ans;
    }
};