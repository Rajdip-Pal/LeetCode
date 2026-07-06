
import java.util.*;

class SolutionOne {

    public int maxIncreasingSubarrays(List<Integer> nums) {
        int count = 1, previous_count = 0, ans = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums.get(i - 1) < nums.get(i)) {
                count++;
            } else {
                previous_count = count;
                count = 1;
            }

            ans = Math.max(ans, count / 2);
            ans = Math.max(ans, Math.min(count, previous_count));
        }

        return ans;
    }
}
