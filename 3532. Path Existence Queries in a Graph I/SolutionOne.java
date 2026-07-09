
import java.util.stream.IntStream;

class UnionFind {

    final private int[] parents;
    final private short[] ranks;

    public UnionFind(int n) {
        parents = new int[n];
        ranks = new short[n];
        IntStream.range(0, n).forEach(i -> {
            parents[i] = i;
            ranks[i] = 0;
        });
    }

    public int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    public boolean isConnected(int x, int y) {
        return find(x) == find(y);
    }

    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (ranks[rootX] > ranks[rootY]) {
                parents[rootY] = rootX;
            } else if (ranks[rootX] < ranks[rootY]) {
                parents[rootX] = rootY;
            } else {
                parents[rootY] = rootX;
                ranks[rootX]++;
            }
        }
    }
}

public class SolutionOne {

    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        UnionFind unionFind = new UnionFind(n);

        for (int i = 1; i < nums.length; i++) {
            if (Math.abs(nums[i] - nums[i - 1]) <= maxDiff) {
                unionFind.union(i, i - 1);
            }
        }

        boolean[] result = new boolean[queries.length];

        IntStream.range(0, queries.length).forEach(i -> {
            result[i] = unionFind.isConnected(queries[i][0], queries[i][1]);
        });

        return result;
    }
}
