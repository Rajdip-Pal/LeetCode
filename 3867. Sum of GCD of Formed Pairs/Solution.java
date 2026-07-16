
import java.util.Arrays;

class Solution {

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public long gcdSum(int[] nums) {
        int mx = Integer.MIN_VALUE;
        int prefixGcd[] = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
            }
            prefixGcd[i] = gcd(mx, nums[i]);
        }

        Arrays.sort(prefixGcd);

        long sum = 0;
        for (int i = 0, j = prefixGcd.length - 1; i < j; i++, j--) {
            sum += gcd(prefixGcd[i], prefixGcd[j]);
        }

        return sum;
    }
}
