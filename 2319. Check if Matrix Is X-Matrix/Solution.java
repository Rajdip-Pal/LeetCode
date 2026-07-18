
public class Solution {

    public static boolean checkXMatrix(int[][] grid) {

        final int n = grid.length;
        boolean ans = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == j || i + j == n - 1)) {
                    if (grid[i][j] == 0) {
                        ans = false;
                        break;
                    }
                } else {
                    if (grid[i][j] != 0) {
                        ans = false;
                        break;
                    }
                }
            }
        }

        return ans;
    }
}
