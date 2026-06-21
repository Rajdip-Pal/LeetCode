
public class SolutionTwo {

    public static int[] findMinMax(int[] arr) {
        int min = arr[0];
        int max = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        return new int[]{min, max};
    }

    private static void countingSort(int[] arr) {
        int[] minmax = findMinMax(arr);
        final int min = minmax[0];
        final int max = minmax[1];

        final int k = max - min + 1;
        int[] frequency = new int[k];

        for (int a : arr) {
            frequency[a - min]++;
        }

        int idx = 0;
        for (int i = 0; i < k; i++) {
            int count = frequency[i];
            for (int j = 0; j < count; j++) {
                arr[idx++] = i + min;
            }
        }
    }

    public int maxIceCream(int[] costs, int coins) {
        countingSort(costs);

        int res = 0, coins_needed = 0;
        boolean outOfBudget = false;

        for (int i = 0; i < costs.length; i++) {
            coins_needed += costs[i];
            if (coins_needed > coins) {
                res = i;
                outOfBudget = true;
                break;
            }
        }

        if (!outOfBudget && res == 0) {
            return costs.length;
        }

        return res;
    }

}
