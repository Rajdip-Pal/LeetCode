
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SolutionOne {

    public int[][] merge(int[][] intervals) {
        List<int[]> list = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        int starting_day = intervals[0][0];
        int current_day = -1;

        for (int[] interval : intervals) {
            if (interval[0] > current_day) {
                list.add(new int[]{starting_day, current_day});
                starting_day = interval[0];
                current_day = interval[1];
            } else {
                current_day = Math.max(current_day, interval[1]);
            }
        }

        return list.toArray(int[][]::new);
    }
}
