
public class Solution {

    class DSU {

        int[] parent = new int[26];
        int[] min = new int[26];

        DSU() {
            for (int i = 0; i < 26; i++) {
                parent[i] = i;
                min[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find(parent[x]);   // Path Compression
        }

        void insert(char a, char b) {
            int pa = find(a - 'a');
            int pb = find(b - 'a');

            if (pa == pb) {
                return;
            }

            // Union
            parent[pb] = pa;

            // Maintain minimum character of the component
            min[pa] = Math.min(min[pa], min[pb]);
        }

        char minEq(char c) {
            return (char) ('a' + min[find(c - 'a')]);
        }
    }

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        final DSU dsu = new DSU();

        for (int i = 0; i < s1.length(); i++) {
            dsu.insert(s1.charAt(i), s2.charAt(i));
        }

        StringBuilder str = new StringBuilder();

        for (char ch : baseStr.toCharArray()) {
            str.append(dsu.minEq(ch));
        }

        return str.toString();
    }
}
