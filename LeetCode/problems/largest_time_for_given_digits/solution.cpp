class Solution {
public:
string largestTimeFromDigits(vector<int>& arr) {
    string result = "";
    int maxTime = -1;
    
    sort(arr.begin(), arr.end(), greater<int>());
    do {
        int hours = arr[0] * 10 + arr[1];
        int minutes = arr[2] * 10 + arr[3];
    
        if (hours <= 23 && minutes <= 59) {
            string currentTime = (hours < 10 ? "0" : "") + to_string(hours) + ":" +
                                 (minutes < 10 ? "0" : "") + to_string(minutes);

            if (stoi(currentTime) > maxTime) {
                maxTime = stoi(currentTime);
                result = currentTime;
            }
        }
    } 
    while (next_permutation(arr.begin(), arr.end(), greater<int>()));

    return result;
}

};