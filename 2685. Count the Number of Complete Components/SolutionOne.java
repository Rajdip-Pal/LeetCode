
public class SolutionOne {

    private boolean[][] graph;
    private boolean[] visited;

    private int vertices;
    private int degSum;

    public int countCompleteComponents(final int n, final int[][] edges) {
        graph = new boolean[n][n];
        visited = new boolean[n];

        for (int[] edge : edges) {
            graph[edge[0]][edge[1]] = true;
            graph[edge[1]][edge[0]] = true;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vertices = 0;
                degSum = 0;

                dfs(i);

                // since edge = degSum / 2
                // maximum edge = vertices * (vertices - 1) / 2 
                if (vertices * (vertices - 1) == degSum) {
                    ans++;
                }
            }
        }

        return ans;
    }

    private void dfs(final int node) {
        visited[node] = true;
        vertices++;
        for (int i = 0; i < graph.length; i++) {
            if (graph[node][i] == true) {
                degSum++;
                if (!visited[i]) {
                    dfs(i);
                }
            }
        }
    }
}
