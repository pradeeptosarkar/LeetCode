class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a>b) swap(a,b);
        if(a>c) swap(a,c);
        if(b>c) swap(b,c);
        return vector<int>{(b-a==1 && c-b==1)?0:(b-a<=2 || c-b<=2)?1:2,b-a-1 + c-b-1};
    }
};