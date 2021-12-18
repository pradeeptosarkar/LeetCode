class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")return "0";
        int n = num1.size();
        int m = num2.size();
        vector<int>ans(n+m,0);
        int p = 0;
        int j=n-1,k=n+m-1;
        int sp = 0;
        for(int i=n-1;i >= 0 ;i--){
            int size = k;
            for(int j=m-1;j>=0;j--){
                //cout<<i<< " "<<j<<endl;
                int temp = (num1[i] - '0')*(num2[j] - '0');
                //cout<<temp<<endl;
                temp = temp + p;
                //cout<<temp<<endl;
                p = temp / 10;
                //cout<<temp<<endl;
                temp = temp % 10;
                //cout<<temp<<endl;
                //cout<<sp<<endl;
                temp = temp + sp + ans[size];
                //cout<<temp<<endl;
                sp = temp/10;
                //cout<<sp<<endl;
                temp = temp % 10;
                //cout<<temp<<endl;
                ans[size--] = temp;
            }
            ans[size] += p;
            p = 0;
            ans[size] += sp;
            sp = 0;
            //break;
            k--;
        }
        string f_ans = "";
        if(ans[0] != 0)f_ans += to_string(ans[0]);
        for(int i=1;i<n+m;i++){
            f_ans += to_string(ans[i]);
        }
        return f_ans;
    }
};