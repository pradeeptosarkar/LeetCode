/*class Solution {
public:
    int numSquares(int n) {
        
    }
};*/

class Solution {

public:

int numSquares(int n) {

    int count=0;

    queue<int> q;

    q.push(n);

    while(!q.empty()) {

        int n=q.size();

        for(int i=0; i<n; i++) {

            int curr=q.front();

            q.pop();

            long long int a=sqroot(curr);

            if(a*a==curr)

                return count+1;

            for(int j=a; j>0; j--) 

                q.push(curr-j*j);

        }

        count++;

    }

 return count;

}

long long int sqroot(int n) {

    int low=0, high=n;

    while(low<=high) {

        long long int mid=low+(high-low)/2;

        if(mid*mid==n)

            return mid;

        else if(mid*mid>n)

            high=mid-1;

        else

            low=mid+1;

    }

 return high;

}

};