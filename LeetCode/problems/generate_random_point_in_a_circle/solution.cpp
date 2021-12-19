class Solution {
double m_radius;
double m_x_center;
double m_y_center;

public:
Solution(double radius, double x_center, double y_center)
: m_radius(radius), m_x_center(x_center), m_y_center(y_center) {
srand(time(NULL));
}

vector<double> randPoint() {
    double ran1 = (double)rand() / RAND_MAX;
    double ran2 = (double)rand() / RAND_MAX;
    
    double angle = ran1 * 2 * M_PI;
	//spread points outwards, not single dimension, but two dimension  
    double radius = sqrt(ran2) * m_radius;
    
    vector<double> rtn;
    rtn.push_back(m_x_center + radius * sin(angle));
    rtn.push_back(m_y_center + radius * cos(angle));
    return rtn;
}
};