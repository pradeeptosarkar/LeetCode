class Solution {
public:
    bool isvalid(vector<int> &arr)
    {
        for(int i='A';i<='Z';i++)  //65 to 90
        {
            if((arr[i]>=1 && arr[i+32]==0) || (arr[i]==0 && arr[i+32]>0)) return false;
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        //longest nice substr
        string ans;
        //O(26*n*n)  //can not do this in O(N)
        
        for(int i=0;i<s.size();i++)
        {
            int j=i;
            vector<int> arr(256,0);
            while(j<s.size())
            {
                arr[s[j]]++;
                j++;
                if(isvalid(arr) && j-i>ans.length())
                {
                    ans=s.substr(i,j-i);
                }
            }
        }
        return ans;
    }
};