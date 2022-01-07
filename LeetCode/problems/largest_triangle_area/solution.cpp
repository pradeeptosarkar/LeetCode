class Solution {
public:
    double length(vector<int>v1,vector<int>v2){
        int x=((v1[0]-v2[0])*(v1[0]-v2[0])+(v1[1]-v2[1])*(v1[1]-v2[1]));
        double y=sqrt(x);
        return y;
    }
    double area(double a,double b,double c){
        double s=(a+b+c)/2.0;
        double x=s*(s-a)*(s-b)*(s-c);
        double y=sqrt(x);
        return y;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double ans=0.0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    double a=length(points[i],points[j]);
                    double b=length(points[i],points[k]);
                    double c=length(points[j],points[k]);
                    ans=max(ans,area(a,b,c));
                }
            }
        }
        return ans;
    }
};