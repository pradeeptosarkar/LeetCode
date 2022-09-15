class Solution {

public:

    vector<int> findOriginalArray(vector<int>& arr) {

        int n = arr.size() ;

        if(n&1)

            return vector<int>() ;

        sort(arr.begin(), arr.end()) ;

        vector<bool> vis(n,false) ;

        vector<int> ans ;

        int i=0 , j=1 , x = 0;

        while(j<n && x<n/2){

            while(vis[i])

                i++ ;

            if(i == j)

                j++ ;

            while(j<n && 2*arr[i] > arr[j])

                j++ ;

            

            if(j == n){

                return vector<int>() ;

            }

            

            if(arr[i]*2 == arr[j]){

                vis[j] = true ;

                ans.push_back(arr[i]) ;

                i++,j++;

                x++ ;

            }else{

                return vector<int>() ;

            }

        }

        

        if(x == n/2)


            return ans ;

        return vector<int>() ;

    }

};
        

