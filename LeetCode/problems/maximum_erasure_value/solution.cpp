class Solution {
    public:

int maximumUniqueSubarray(vector<int>& nums) {

        int ret=0, sum=0, i=0, n=nums.size();

        vector<bool> found(10001,false);

        for(int j=0; j<n; j++){

            sum += nums[j];

            if(!found[nums[j]]){

                found[nums[j]] = true;

            }

            else {

                while(nums[i]!=nums[j]){

                    sum -= nums[i];

                    found[nums[i++]] = false;

                }

                sum-=nums[i];

                i++;

            }

            ret = max(ret, sum);

        }

        return ret;

    }
        };

