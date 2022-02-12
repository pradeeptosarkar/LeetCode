class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr, int k, unordered_map<int, int> counter) {
        vector<int> ans;
        vector<int> emptyArr;
        /*Step 3.1
            For each J, reduce the counter of arr[i] and arr[i] + 2*K by 1
            If for some arr[i], arr[i] + 2*K doesn't exist or it's count can't be reduced further, then the K is invalid
        */
        for(int i = 0; i < arr.size(); i++){
            if(counter[arr[i]] > 0){
                ans.push_back(arr[i] + k);
                counter[arr[i]]--;
                if(counter[arr[i] + 2*k] <= 0)
                    return emptyArr;
                counter[arr[i] + 2*k]--;
            }
        }
        return ans;
    }
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> listOfValidKs;
        /*Step 1: Find the list of valid K's*/
        for(int i = 1; i <= nums.size()/2; i++){
            if(nums[i] != nums[0] && (nums[i] - nums[0])%2 == 0){
                listOfValidKs.push_back((nums[i] - nums[0])/2);
            }
        }
        /*!Step 1*/
        /*Step 2: Maintain the counter*/
        unordered_map<int, int> counter;
        for(int i = 0; i < nums.size(); i++)
            counter[nums[i]]++;
        /*!Step 2*/
        /*Step 3: Validate each K*/
        for(int i = 0; i < listOfValidKs.size(); i++){
            ans = findOriginalArray(nums, listOfValidKs[i], counter);
            if(ans.size() > 0)
                return ans;
        }
        /*!Step 3*/
        ans.clear();
        return ans;
    }
};