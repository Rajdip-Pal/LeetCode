
import java.util.Arrays;
import java.util.HashMap;

public class SolutionOne {

    public int[] arrayRankTransform(int[] arr) {
        if (arr == null || arr.length == 0) {
            return new int[0];
        }

        int[] result = arr.clone();
        Arrays.sort(arr);

        HashMap<Integer, Integer> map = new HashMap<>(arr.length);
        int rank = 1;

        map.put(arr[0], rank++);
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != arr[i - 1]) {
                map.put(arr[i], rank++);
            }
        }

        for (int i = 0; i < arr.length; i++) {
            result[i] = map.get(result[i]);
        }

        return result;
    }
}
