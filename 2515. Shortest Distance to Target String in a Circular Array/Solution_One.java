
public class Solution_One {

    public int closestTarget(String[] words, String target, int startIndex) {
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < words.length; i++) {
            if (words[i].equals(target)) {
                final int dist = Math.abs(i - startIndex);
                ans = Math.min(ans, Math.min(dist, words.length - dist));
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
