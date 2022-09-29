class Solution {



public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        vector<int> r;

        int size = arr.size();

        if (x <= arr[0]) {

            for (int i = 0; i < k; ++i) {

                r.push_back(arr[i]);

            }

            return r;

        }

        if (x >= arr.back()) {

            for (int i = k; i >= 1; --i) {

                r.push_back(arr[size - i]);

            }

            return r;

        }

        auto it = lower_bound(arr.begin(), arr.end(), x);

        int x_idx = distance(arr.begin(), it);

        int s = max(0, x_idx - k - 1);      

        int e = min(size - k, x_idx);        

        while (s < e) {

            int mid = (s + e) / 2;

            if ((x - arr[mid]) > (arr[mid + k - 1] - x)) {

                if (arr[mid + k] - x >= x - arr[mid]) {

                    

                    e = mid;

                } else {

                    s = mid + 1;

                }

            } else {

                e = mid;

            }


        }

        for (int i = 0; i < k; ++i) {

            r.push_back(arr[s + i]);

        }

        return r;

    }


        

};