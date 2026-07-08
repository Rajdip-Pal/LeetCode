
class SolutionOne {

    private static final int MOD = 1_000_000_007;
    private static final int MAX_DIGITS = 100_001;
    private static final long[] POW10 = new long[MAX_DIGITS];

    static {
        POW10[0] = 1;
        for (int i = 1; i < MAX_DIGITS; i++) {
            POW10[i] = (POW10[i - 1] * 10) % MOD;
        }
    }

    public int[] sumAndMultiply(String s, int[][] queries) {

        final int digits = s.length();
        final int[] prefixSum = new int[digits + 1];
        final long[] x = new long[digits + 1];
        final int[] cnt = new int[digits + 1];

        for (int i = 1; i <= digits; i++) {
            final int digit = s.charAt(i - 1) - '0';
            prefixSum[i] = prefixSum[i - 1] + digit;
            x[i] = digit > 0 ? (x[i - 1] * 10 + digit) % MOD : x[i - 1];
            cnt[i] = cnt[i - 1] + (digit > 0 ? 1 : 0);
        }

        final int queriesLength = queries.length;
        final int[] result = new int[queriesLength];

        for (int i = 0; i < queriesLength; i++) {
            final int l = queries[i][0];
            final int r = queries[i][1] + 1;

            final int length = cnt[r] - cnt[l];
            final long sum = prefixSum[r] - prefixSum[l];
            final long val_x = (x[r] - ((x[l] * POW10[length]) % MOD) + MOD) % MOD;

            result[i] = (int) ((val_x * sum) % MOD);
        }

        return result;
    }
}
