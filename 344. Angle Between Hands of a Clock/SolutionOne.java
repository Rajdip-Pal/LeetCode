
public class SolutionOne {

    public double angleClock(int hour, int minutes) {

        double degree_M = minutes * 6;
        double degree_H = hour * 30 + minutes / 2.0;

        double angle = Math.abs(degree_H - degree_M);
        double res = Math.min(angle, 360 - angle);

        return res;
    }
}
