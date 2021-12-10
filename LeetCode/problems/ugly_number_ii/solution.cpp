class Solution {
public:
    int nthUglyNumber(int n) 
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        

        vector<vector<int>> primes = {{2,INT_MAX/2},

                                      {3,INT_MAX/3},

                                      {5, INT_MAX/5}};

        

        int val = 1, fact = 1;

        int multiplier, upperLimit;

        

        pq.push({val, fact});

        

        for(int i = 0; i < n; ++i){

            vector<int> t = pq.top(); pq.pop();

            val = t[0];

            fact = t[1];

            // cout << "val: " << val << ", fact: " << fact << endl;

            

            for(int i = 0; i < primes.size(); ++i){

                multiplier = primes[i][0];

                upperLimit = primes[i][1];

                /*

                consider the number 6 = 2*3 = 3*2,

                if can be formed of (val=2)*(multiplier=3) or

                (val=3)*(multiplier=2),

                so there is a duplicate.

                To avoid the duplicate, we add a restriction that

                current multiplier should be >= fact.

                e.g. when val's last fact is 3, we won't multiply it by 2

                

                note: it works like the ascending permutation of prime numbers

                */

                if(multiplier >= fact && val < upperLimit){

                    pq.push({val*multiplier, multiplier});

                }

            }

        }

        

        return val;
    }
};