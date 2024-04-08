class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int circleStudentCount = 0;
        int squareStudentCount = 0;

        
        for (int student : students) 
        {
            if (student == 0) 
                circleStudentCount++;
             
            else 
                squareStudentCount++;
        }
        
        for (int sandwich : sandwiches) 
        {
            if (sandwich == 0 && circleStudentCount == 0) 
                return squareStudentCount;
            
            if (sandwich == 1 && squareStudentCount == 0) 
                return circleStudentCount;
            
            if (sandwich == 0) 
                circleStudentCount--;
            
            else 
                squareStudentCount--;
        }
        
        return 0;
    }
};
