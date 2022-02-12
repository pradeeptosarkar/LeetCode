int MAXN=1e5+1;
struct treeNode{
    bool candle;
    int leftplate;
    int rightplate;
    int sum;
    treeNode(){
        candle=0;leftplate=rightplate=0;sum=0;
    }
    treeNode(bool y){
        candle=y;
        if(y) leftplate=rightplate=sum=0;
        else leftplate=rightplate=1,sum=0;
    }
};
int n;

vector<treeNode> t(4*MAXN);
treeNode merge(treeNode x, treeNode y){
    treeNode res=treeNode();
    res.candle= x.candle | y.candle;
    if(x.candle && y.candle){
        res.sum= (x.sum+y.sum+x.rightplate+y.leftplate);
        res.leftplate=x.leftplate;
        res.rightplate=y.rightplate;      
    }
    else if(x.candle){
        res.sum=x.sum;
        res.leftplate=x.leftplate;
        res.rightplate=x.rightplate+y.leftplate;
    }
    else if(y.candle){
        res.sum=y.sum;
        res.leftplate=x.rightplate+y.leftplate;
        res.rightplate=y.rightplate;
    }
    else{
        res.sum=0;
        res.leftplate=res.rightplate=x.leftplate+y.rightplate;
    }
    return res;
}
void build(string &s, int v, int tl, int tr) {
    
    if (tl == tr) {
        t[v] = treeNode(s[tl]=='|');
    } else {
        int tm = (tl + tr) / 2;
        build(s, v*2, tl, tm);
        build(s, v*2+1, tm+1, tr);
        t[v] = merge(t[v*2], t[v*2+1]);
    }
}
treeNode query(int v, int tl, int tr, int l, int r) {
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if(l<=min(r,tm) && r>=max(l, tm+1)) return merge(query(v*2, tl, tm, l, min(r, tm)) ,query(v*2+1, tm+1, tr, max(l, tm+1), r));
    else if( r>=max(l, tm+1)) return query(v*2+1, tm+1, tr, max(l, tm+1), r);
    else if(l<=min(r,tm)) return query(v*2, tl, tm, l, min(r, tm));
    return  new treeNode();
}
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
       
        int n=s.length();
        build(s,1,0,n-1);
        vector<int> ans;
        for(auto &i:queries){
            ans.push_back(query(1,0,n-1,i[0],i[1]).sum);
        }
        return ans;
    }
};