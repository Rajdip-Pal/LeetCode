
import java.util.List;

public class SolutionOne {

    static final int MOD = 1_000_000_007;

    private class MaxPath {

        public final int val, way;

        public MaxPath(int val, int way) {
            this.val = val;
            this.way = way;
        }

        public MaxPath() {
            this.val = 0;
            this.way = 0;
        }

        @Override
        public String toString() {
            return "[ " + val + ", " + way + "]";
        }

        static int[] toArray(MaxPath p) {
            return p == null ? new int[]{0, 0} : new int[]{p.val, p.way};
        }

    }

    public int[] pathsWithMaxScore(List<String> board) {
        final int n = board.size();

        int[][] matrix = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = board.get(i).charAt(j);
            }
        }

        MaxPath[][] ans = new MaxPath[n][n];
        ans[n - 1][n - 1] = new MaxPath(0, 1);

        for (int i = n - 2; i >= 0; i--) {
            // X -axis
            MaxPath prevX = ans[n - 1][i + 1];

            if (matrix[n - 1][i] != 'X' && prevX != null) {
                ans[n - 1][i] = new MaxPath((matrix[n - 1][i] - '0') + prevX.val, 1);
            }

            // Y -axis
            MaxPath prevY = ans[i + 1][n - 1];

            if (matrix[i][n - 1] != 'X' && prevY != null) {
                ans[i][n - 1] = new MaxPath((matrix[i][n - 1] - '0') + prevY.val, 1);
            }

        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (matrix[i][j] != 'X') {
                    MaxPath[] prev = {
                        ans[i + 1][j], // up
                        ans[i + 1][j + 1], // diagonal
                        ans[i][j + 1] // left
                    };

                    int bestVal = -1;
                    int ways = 0;

                    for (MaxPath p : prev) {
                        if (p == null) {
                            continue;
                        }

                        if (p.val > bestVal) {
                            bestVal = p.val;
                            ways = p.way;
                        } else if (p.val == bestVal) {
                            ways = (ways + p.way) % MOD;
                        }
                    }

                    if (bestVal != -1) {
                        int score = matrix[i][j] == 'E' ? 0 : matrix[i][j] - '0';
                        ans[i][j] = new MaxPath(bestVal + score, ways);
                    }
                }
            }
        }

        return MaxPath.toArray(ans[0][0]);
    }

}
