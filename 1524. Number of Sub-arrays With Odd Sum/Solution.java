
class Solution {

    static final int MOD = (int) (1e9 + 7);

    static boolean is_odd(int x) {
        return (x & 1) == 1;
    }

    public int numOfSubarrays(final int[] arr) {
        final int n = arr.length;
        final int[] prefix_sum = new int[n];
        final int[] prev_odd_sum = new int[n];
        final int[] prev_even_sum = new int[n];

        int odd_sums = 0, even_sums = 0;

        for (int i = 0; i < n; i++) {
            prefix_sum[i] = (i > 0 ? prefix_sum[i - 1] : 0) + arr[i];
            prev_odd_sum[i] = odd_sums;
            prev_even_sum[i] = even_sums;
            int _ = is_odd(prefix_sum[i]) ? odd_sums++ : even_sums++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (is_odd(prefix_sum[i])) {
                ans += 1 + prev_even_sum[i];
            } else {
                ans += prev_odd_sum[i];
            }
            ans %= MOD;
        }

        return ans;
    }
}
