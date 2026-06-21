
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class SolutionOne {

    public int[][] colorGrid(int n, int m, int[][] sources) {
        int[][] grid = new int[n][m];
        Queue<int[]> q = new LinkedList<>();

        final int[] d = {0, 1, 0, -1, 0};

        for (int[] s : sources) {
            grid[s[0]][s[1]] = s[2];
            q.offer(s);
        }

        while (!q.isEmpty()) {
            int size = q.size();
            Map<Integer, Integer> mp = new HashMap<>();

            for (int k = 0; k < size; k++) {
                int[] node = q.poll();
                int x = node[0], y = node[1], val = node[2];

                for (int i = 0; i < 4; i++) {
                    int nx = x + d[i], ny = y + d[i + 1];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }

                    if (grid[nx][ny] != 0) {
                        continue;
                    }

                    int key = nx * m + ny;
                    mp.merge(key, val, Math::max);

                }
            }

            for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
                int x = entry.getKey() / m;
                int y = entry.getKey() % m;
                int color = entry.getValue();

                grid[x][y] = color;

                q.offer(new int[]{x, y, color});
            }
        }

        return grid;
    }
}
