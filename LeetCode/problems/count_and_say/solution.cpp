/*lass Solution {
public:
    string countAndSay(int n) {
        
    }
};*/

class Solution {

public:

    string countAndSay(int n) {

        if(n == 1){

            return "1";

        }

        queue<char> q;

        string a = "1";

        while(n>1){

            for(auto i: a){

                q.push(i);

            }

            a="";

            int count=1;

            char exist = q.front();

            q.pop();

            while(!q.empty()){

                char x = q.front();

                q.pop();

                if(exist != x){

                    a.push_back(count+'0');

                    a.push_back(exist);

                    count = 1;

                }

                else{

                    count++;

                }

                

                exist = x;

            }

            a.push_back(count+'0');

            a.push_back(exist);

            n--;

        }

        return a;

    }

};