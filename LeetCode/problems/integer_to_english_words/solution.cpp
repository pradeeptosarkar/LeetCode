class Solution {
private:
    const int thresholds[4] {1000000000,1000000,1000, 100};
    const string powDictonary[4] = {" Billion"," Million"," Thousand", " Hundred"};
    const string lowDictonary[16] = {"Zero", "One", "Two", "Three", 
                              "Four", "Five","Six", "Seven", "Eight", "Nine",
                              "Ten", "Eleven", "Twelve","Thirteen","Fourteen"};
    const string sub100Dic[8] = {"Twen","Thir","For",
                                 "Fif","Six","Seven","Eigh","Nine"};
public:      
    
    string numberToWords(int num, int thresholdInx = 0) 
    {
        
        if(num < 15) return lowDictonary[num];
        if(num < 20) return sub100Dic[num - 12] + "teen";
        if(num < 100) return sub100Dic[num/10 -2]+(num % 10 ? "ty " + lowDictonary[num % 10] : "ty");
        
             
        while(num<thresholds[thresholdInx])
        {
            thresholdInx++;
        }
        
        int x = thresholds[thresholdInx], up=num/x, below=num%x;
               
        if(!below) 
            return numberToWords(up, thresholdInx + 1) + powDictonary[thresholdInx];
        
        return numberToWords(up, thresholdInx + 1) + powDictonary[thresholdInx]  + " " + 
            numberToWords(below, thresholdInx + 1);       
    }
};