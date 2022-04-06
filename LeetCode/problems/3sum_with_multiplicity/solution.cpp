class Solution {
public:
    int pairSum(vector<int> &arr, int start, int end, int target) {
        const int mod = 1e9 + 7;
        int count = 0;
        while (start < end) {
            if (arr[start] + arr[end] < target) {
                start++;
            } else if (arr[start] + arr[end] > target) {
                end--;
            } else {
                int elementAtStart = arr[start];
                int elementAtEnd = arr[end];
                if (elementAtStart == elementAtEnd) {
                    int totalElementsFromStartToEnd = end - start + 1;
                    count += (totalElementsFromStartToEnd * (totalElementsFromStartToEnd - 1) / 2);
                    count %= mod;
                    return count;
                }
                int tmpStart = start + 1;
                int tmpEnd = end - 1;
                while (tmpStart <= tmpEnd && arr[tmpStart] == elementAtStart) {
                    tmpStart += 1;
                }
                while (tmpStart <= tmpEnd && arr[tmpEnd] == elementAtEnd) {
                    tmpEnd--;
                }
                int totalElementsFromStart = tmpStart - start;
                int totalElementsFromEnd = end -tmpEnd;
                count += (totalElementsFromStart * totalElementsFromEnd);
                count %= mod;
                start = tmpStart;
                end = tmpEnd;
            }
        }
        count %= mod;
        return count;
    }
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        sort(arr.begin() , arr.end());
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int pairSumFor = target - arr[i];
            int countOfPairs = pairSum(arr, i + 1, n - 1, pairSumFor);
            countOfPairs %= mod;
            count += countOfPairs;
            count %= mod;
        }
        return count;
    }
};