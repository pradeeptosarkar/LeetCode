class Solution {
public:
    #define MAX 15
    #define INF (int)(1e9)
    vector<int> values[2][MAX+1]; 

    void get_comb(vector<int>& v, int loc){
        int lim = (1 << v.size());
        for(int i=0;i<lim;i++){
            int d = i;
            int sum = 0;
            int cnt = 0;
            for(int n=0;n<v.size();n++){
                if((d & 1) == 1){
                    sum += v[n];
                    cnt++;
                }
                d = d >> 1;
            }
            values[loc][cnt].emplace_back(sum);
        }
    }
    void value_sort(){
        for(int i=0;i<=MAX;i++){
            sort(values[0][i].begin(), values[0][i].end());
            sort(values[1][i].begin(), values[1][i].end());
            values[0][i].erase(unique(values[0][i].begin(), values[0][i].end()), values[0][i].end());
            values[1][i].erase(unique(values[1][i].begin(), values[1][i].end()), values[1][i].end());
        }
    }
    
    void update(int& ans, int e, int x, int total){
        int value = abs(-2*e - 2*x + total);
        if(value < ans){
            ans = value;
        }
    }
    
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int total = 0;
        vector<int> left(n), right(n);
        for(int i=0;i<n;i++){
            left[i] = nums[i];
            right[i] = nums[i+n];
            total += nums[i];
            total += nums[i+n];
        }
        get_comb(left, 0);
        get_comb(right, 1);
        int ans = INF;
        value_sort();
        for(int i=0;i<=n;i++){
            for(int e : values[0][i]){
                auto lower = lower_bound(values[1][n-i].begin(), values[1][n-i].end(), (total - 2*e + 1)/2);
                if(lower != values[1][n-i].end()){
                    update(ans, e, *(lower), total);
                }
                if(lower != values[1][n-i].begin()){
                    lower--;
                    update(ans, e, *(lower), total);
                }
            }
        }
        return ans;
    }
};