/**
 * 
 * Leetcode : https://leetcode.com/problems/angle-between-hands-of-a-clock/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * explaination : Read editorial for explaination
 * 
*/

class Solution {
public:

    // Read editorial for explaination

    double angleClock(int hour, int minutes) {
        int oneMinuteAngle = 6;
        int oneHourAngle = 30;

        double minuteAngle = minutes * oneMinuteAngle;
        double hourAngle = ((hour%12) + minutes/60.0) * oneHourAngle;

        double diff = abs(hourAngle - minuteAngle);
        return std::min(diff, 360-diff);
    }
};