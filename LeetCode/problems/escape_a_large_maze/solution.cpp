#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    bool isEscapePossible(vvi& b, vi& s, vi& t) {
        int n=b.size(),i,diff=0;
        bool fs=0,ft=0;
        int mxx=1e5;
        int mr=s[0],mc=s[1];
        
        set<vector<int>> blk,vis;
        for(auto v:b)
            blk.insert(v);
        
        queue<vector<int>> q;
        q.push({s[0],s[1]});
        vis.insert({s[0],s[1]});
        
        while(q.size()){
            vector<int> p=q.front();
            q.pop();
            diff=max({diff,abs(p[1]-s[1]),abs(p[0]-s[0])});
            
            if(p==t)
                return 1;
            
            if(diff>=b.size()){
                fs=1;
                break;
            }
            
            if(p[0]+1<mxx && blk.find({p[0]+1,p[1]})==blk.end() && vis.find({p[0]+1,p[1]})==vis.end()){
                q.push({p[0]+1,p[1]});
                vis.insert({p[0]+1,p[1]});
            }
            
            if(p[1]+1<mxx && blk.find({p[0],p[1]+1})==blk.end() && vis.find({p[0],p[1]+1})==vis.end()){
                q.push({p[0],p[1]+1});
                vis.insert({p[0],p[1]+1});
            }
            
            if(p[0] && blk.find({p[0]-1,p[1]})==blk.end() && vis.find({p[0]-1,p[1]})==vis.end()){
                q.push({p[0]-1,p[1]});
                vis.insert({p[0]-1,p[1]});
            }
            
            if(p[1] && blk.find({p[0],p[1]-1})==blk.end() && vis.find({p[0],p[1]-1})==vis.end()){
                q.push({p[0],p[1]-1});
                vis.insert({p[0],p[1]-1});
            }
        }
        
        if(!fs)
            return 0;
        
        mr=t[0],mc=t[1];
        while(q.size())
            q.pop();
        
        vis.clear();
        
        q.push({t[0],t[1]});
        vis.insert({t[0],t[1]});
        diff=0;
        
        while(q.size()){
            vector<int> p=q.front();
            q.pop();
            
            diff=max({diff,abs(p[1]-t[1]),abs(p[0]-t[0])});
            
            if(p==s)
                return 1;
            
            if(diff>=b.size()){
                ft=1;
                break;
            }
            
            if(p[0]+1<mxx && blk.find({p[0]+1,p[1]})==blk.end() && vis.find({p[0]+1,p[1]})==vis.end()){
                q.push({p[0]+1,p[1]});
                vis.insert({p[0]+1,p[1]});
            }
            
            if(p[1]+1<mxx && blk.find({p[0],p[1]+1})==blk.end() && vis.find({p[0],p[1]+1})==vis.end()){
                q.push({p[0],p[1]+1});
                vis.insert({p[0],p[1]+1});
            }
            
            if(p[0] && blk.find({p[0]-1,p[1]})==blk.end() && vis.find({p[0]-1,p[1]})==vis.end()){
                q.push({p[0]-1,p[1]});
                vis.insert({p[0]-1,p[1]});
            }
            
            if(p[1] && blk.find({p[0],p[1]-1})==blk.end() && vis.find({p[0],p[1]-1})==vis.end()){
                q.push({p[0],p[1]-1});
                vis.insert({p[0],p[1]-1});
            }
        }
        
        if(!ft)
            return 0;
        return 1;
    }
};