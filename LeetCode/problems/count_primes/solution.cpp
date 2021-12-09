class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n + 1, false);

    int count = 0;

    for (int i = 2; i < n; i++) {

        if (!sieve[i]) {

            count++;

            for (int j = i; j < n; j += i) {

                sieve[j] = true;

            }

        }

    }

    return count;      
    }
};