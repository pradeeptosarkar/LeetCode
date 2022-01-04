class Solution {
public:
    int check(vector<int>&student,vector<int>&mentor){
        int i=0,sum=0;
        while(i<student.size()){
            if(student[i]==mentor[i])sum++;
            i++;
        }
        return sum;
    }
    void solve(vector<vector<int>>&students,vector<vector<int>>&mentors,int sum,int i, int &max_compat){
        if(i==students.size()){
            max_compat=fmax(sum,max_compat);
            return;
        }
        int n=students.size();
        for(int j=i;j<n;j++){
            swap(mentors[i],mentors[j]);
            solve(students,mentors,sum+check(students[i],mentors[i]),i+1,max_compat);
            swap(mentors[i],mentors[j]);
        }
        return;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int max_compat=0;
        solve(students,mentors,0,0,max_compat);
        return max_compat;
    }
};