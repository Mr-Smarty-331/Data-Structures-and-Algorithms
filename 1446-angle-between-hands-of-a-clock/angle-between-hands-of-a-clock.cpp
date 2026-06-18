class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min=minutes/60.0;
        double h = (hour + (double)min)/12.0;
        double angle = abs(min-h)*360;
        if(angle>180) return 360-angle;
        return (angle);
    }
};