class Solution {
public:
    long long int calculateElement(int n, int r){
        long long int k = 1;
        for(int i=1; i<=r; i++){
            k*=n;
            k/=i;
            n--;
        }
        return k;
    }
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        vector<int> row(n);
        for(int i=0; i<n; i++){
            row[i] = (calculateElement(rowIndex, i));
        }
        return row;
    }
};