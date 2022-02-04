# Generate Random Point in a Circle
class Solution {
public:
  double x;
    double y;
    double r;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    vector<double> randPoint() {
        double rad = (double)rand() / RAND_MAX;
        rad = sqrt(rad) * r; 
        double t = (double)rand() / RAND_MAX;
        t*= 360.0;
        return {x+rad*cos(t),y+rad*sin(t)}; 
    }
};
