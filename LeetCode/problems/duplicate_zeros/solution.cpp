class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int countZ = 0;
        for (int elm : arr)
            if (elm == 0) countZ++;
        
        int m = arr.size();

        for (int i = m - 1; i >= 0; i--) {
            if (i + countZ < m)
                arr[i + countZ] = arr[i];
            
            if (arr[i] == 0) {
                countZ--;

                if (i + countZ < m)
                    arr[i + countZ] = arr[i];
            }
        }
    }
};