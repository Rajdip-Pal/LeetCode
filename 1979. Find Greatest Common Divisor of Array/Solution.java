
public class Solution {

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public int findGCD(int[] nums) {
        int mx = Integer.MIN_VALUE;
        int mn = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
            }

            if (nums[i] < mn) {
                mn = nums[i];
            }
        }

        return gcd(mx, mn);
    }
}
