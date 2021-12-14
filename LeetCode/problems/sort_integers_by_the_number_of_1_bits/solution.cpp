class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), [this](int a, int b){
                    if( countBits(a) == countBits(b) ) return ( a < b );
                    return ( countBits(a) < countBits(b) );
                });
        return arr;
    }

private:
    int countBits(int tmp){
        int one_bit = 0;
        while( tmp != 0 ){
            if( tmp % 2 != 0 ) one_bit++;
            tmp /= 2;
        } return one_bit;
    }
};