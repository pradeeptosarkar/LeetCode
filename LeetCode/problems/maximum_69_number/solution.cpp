class Solution {
public:
    int maximum69Number (int num) 
    {
        string result=to_string(num);
        for(int i=0;i<result.length();i++)
        {
            if(result[i]=='6')
            {
                result[i]='9';
                break;
            }
        }
        return stoi(result);
    }
};