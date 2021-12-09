class Solution {

public:

    bool isUgly(int num) {

        const vector<int> factors{2, 3, 5};

        for (const int factor : factors)

            while (num && num % factor == 0) num /= factor;

        return num == 1;

    }

};
        

