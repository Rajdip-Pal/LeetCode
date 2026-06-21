
import java.util.Arrays;

public class Solutionone {

    public int maxIceCream(int[] costs, int coins) {

        Arrays.sort(costs);
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
