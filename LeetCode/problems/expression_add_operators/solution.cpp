class Solution {
public:
    vector<string> expressions;
    vector<string> addOperators(string num, int target) {
        dfs(num , target , 0 , "" , 0 , 0);
        return expressions;
    }
    void dfs(string &num , int target , int index , string path , long int res , long int prev)
    {
        if(index == num.size() and res == target)
        {
            expressions.push_back(path);
            return;
        }
        
        long int number = 0;
        string sub_string = "";
        
        for(int i = index ; i < num.size() ; ++i)
        {
            sub_string += num[i];
            number = (number * 10) + num[i] - '0';
            
            if(sub_string.size() > 1 and sub_string[0] == '0') // skipping numbers with leading 0's
                break;
            
            if(index == 0) // first number of expression is picked without operator
            {
                dfs(num , target , i + 1 , sub_string , number, number);
            }
            else
            {
                // (1) + operation inserted
                dfs(num , target , i + 1 , path  + "+" + sub_string , res  + number , number);
                    
                // (2) - operation inserted
                dfs(num , target , i + 1 , path + "-" + sub_string , res  - number , -number);
                
                // (3) * operation inserted
                dfs(num , target , i + 1 , path + "*" + sub_string , (res - prev)  + (prev * number) , prev * number);
            }
        }
            
    }
    
};