class Solution {
public:
    //for checking if year is leap or not
    bool isLeap(int year){
        return ((year%4==0 && year%100!=0)||(year%400==0));
    }
    
    //for checking no of days in month
    int daysInMonth(int month,int year){
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
            return 31;
        if(month==2)
            return isLeap(year)?29:28;
        return 30;
    }
    
    //function to calculate days from 1971 to current date
    int stringToInt(string s){
        int year=stoi(s.substr(0,4));
        int month=stoi(s.substr(5,2));
        int days=stoi(s.substr(8,2));
        
        int total_days=0;
        for(int i=1971;i<year;i++){
            total_days+=isLeap(i)?366:365;
        }
        for(int i=1;i<month;i++){
            total_days+=daysInMonth(i,year);
        }
        
        return total_days+days+1;
    }
    
    //main
    int daysBetweenDates(string date1, string date2) {
        return abs(stringToInt(date2)-stringToInt(date1));
        
    }
};