class Solution 
{

public:

    int calculate(string s) 
    {

        stack<int> opds;

        stack<int> signs;

        

        int opd = 0;

        int res = 0;

        int sign = 1;

        

        for(char c : s){

            if(c >= '0' && c <= '9'){

                opd = opd * 10 + (c-'0');

            }else if(c == '+'){

                  res += sign * opd;

                opd = 0;

                sign = 1;

            }else if(c == '-'){

                
                res += sign * opd;

                opd = 0;

                sign = -1;

            }else if(c == '('){



                opds.push(res);

                signs.push(sign);



                res = 0; 

                sign = 1;

            }else if(c == ')'){

                

                res += sign * opd;

                res *= signs.top(); signs.pop();

                res += opds.top(); opds.pop();

                

                opd = 0; 



            }

        }

        


        return res + sign * opd;

    }

};
        

