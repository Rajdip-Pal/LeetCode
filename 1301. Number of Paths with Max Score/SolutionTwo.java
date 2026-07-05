
import java.util.Arrays;
import java.util.List;

public class SolutionTwo {

    static final int MOD = 1_000_000_007;

    public int[] pathsWithMaxScore(List<String> board) {
        int n = board.size();

        char[][] grid = new char[n][];
        for (int i = 0; i < n; i++) {
            grid[i] = board.get(i).toCharArray();
        }

        int[][] values = new int[n][n];
        int[][] ways = new int[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(values[i], -1);
        }

        values[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        // Last row
        for (int j = n - 2; j >= 0; j--) {
            if (grid[n - 1][j] != 'X' && values[n - 1][j + 1] != -1) {
                values[n - 1][j] = values[n - 1][j + 1] + (grid[n - 1][j] - '0');
                ways[n - 1][j] = 1;
            }
        }

        // Last column
        for (int i = n - 2; i >= 0; i--) {
            if (grid[i][n - 1] != 'X' && values[i + 1][n - 1] != -1) {
                values[i][n - 1] = values[i + 1][n - 1] + (grid[i][n - 1] - '0');
                ways[i][n - 1] = 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            int[] valueRow = values[i];
            int[] valueDown = values[i + 1];

            int[] wayRow = ways[i];
            int[] wayDown = ways[i + 1];

            for (int j = n - 2; j >= 0; j--) {
                char ch = grid[i][j];

                if (ch == 'X') {
                    continue;
                }

                int bestVal = -1;
                int totalWays = 0;

                // Down
                if (valueDown[j] != -1) {
                    bestVal = valueDown[j];
                    totalWays = wayDown[j];
                }

                // Diagonal
                if (valueDown[j + 1] != -1) {
                    if (valueDown[j + 1] > bestVal) {
                        bestVal = valueDown[j + 1];
                        totalWays = wayDown[j + 1];
                    } else if (valueDown[j + 1] == bestVal) {
                        totalWays += wayDown[j + 1];
                        if (totalWays >= MOD) {
                            totalWays -= MOD;
                        }
                    }
                }

                // Right
                if (valueRow[j + 1] != -1) {
                    if (valueRow[j + 1] > bestVal) {
                        bestVal = valueRow[j + 1];
                        totalWays = wayRow[j + 1];
                    } else if (valueRow[j + 1] == bestVal) {
                        totalWays += wayRow[j + 1];
                        if (totalWays >= MOD) {
                            totalWays -= MOD;
                        }
                    }
                }

                if (bestVal == -1) {
                    continue;
                }

                valueRow[j] = bestVal + (ch == 'E' ? 0 : ch - '0');
                wayRow[j] = totalWays;
            }
        }

        return values[0][0] == -1
                ? new int[]{0, 0}
                : new int[]{values[0][0], ways[0][0]};
    }
}
