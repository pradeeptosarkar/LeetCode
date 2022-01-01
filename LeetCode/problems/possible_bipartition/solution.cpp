class UnionFind
{
    private:
    
    vector<int> uf_;
    
    public:
    
    UnionFind(int n): uf_(n)
    {
        iota(uf_.begin(),uf_.end(),0);
    }    
    
    int find(int x)
    {
        while(uf_[x]!=x)
        {
            uf_[x]=uf_[uf_[x]];
            x=uf_[x];
        }
        return x;
    }
    
    void join(int x, int y)
    {
        x=find(x);
        y=find(y);
        uf_[y]=x;
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        UnionFind uf(2*n+1);
        
        for(const vector<int>& dislike: dislikes)
        {
            int a=dislike[0];
            int b=dislike[1];
            uf.join(a,b+n);
            uf.join(b,a+n);
        }
        
        for(int i=1;i<=n;++i)
        {
            if(uf.find(i)==uf.find(i+n))
                return false;
        }
        
        return true;
    }
};