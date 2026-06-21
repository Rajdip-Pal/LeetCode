
import java.util.Arrays;

public class SolutionOne {

    public static int countDays(int days, int[][] meetings) {
        int res = 0;
        int current_day = 1;

        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);

        // Starting date to first meeting day
        res += Math.max(0, meetings[0][0] - current_day);

        current_day = meetings[0][1];
        for (int i = 1; i < meetings.length; i++) {
            if (meetings[i][0] > current_day) {
                res += meetings[i][0] - current_day - 1;
            }
            current_day = Math.max(meetings[i][1], current_day);
        }

        // Ending meeting date to last date
        res += Math.max(0, days - current_day);

        return res;
    }

    public static void main(String[] args) {
        int res = countDays(
                57,
                new int[][]{{3, 49}, {23, 44}, {21, 56}, {26, 55}, {23, 52}, {2, 9}, {1, 48}, {3, 31}}
        );
        System.out.println(res);
    }
}
