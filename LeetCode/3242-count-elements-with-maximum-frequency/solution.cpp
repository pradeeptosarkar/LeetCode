class Solution {

public:

    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int, int> frequencies;

        int maxFrequency = 0;

        int totalFrequencies = 0;

   

        for (int num : nums) {

            frequencies[num]++;

            int frequency = frequencies[num];





            if (frequency > maxFrequency) {

                maxFrequency = frequency;

                totalFrequencies = frequency;

             
            } else if (frequency == maxFrequency) {

                totalFrequencies += frequency;

            }

        }

        return totalFrequencies;

    }

};
        


