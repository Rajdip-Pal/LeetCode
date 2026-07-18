
class Solution {

    public int minNumber(int[] nums1, int[] nums2) {
        final boolean[] mark = new boolean[10];

        int mn1 = 10, mn2 = 10;
        for (int i = 0; i < nums1.length; i++) {
            mark[nums1[i]] = true;
            if (nums1[i] < mn1) {
                mn1 = nums1[i];
            }
        }

        int ans = 10;
        for (int i = 0; i < nums2.length; i++) {
            if (mark[nums2[i]]) {
                if (ans > nums2[i]) {
                    ans = nums2[i];
                }
            }

            if (nums2[i] < mn2) {
                mn2 = nums2[i];
            }
        }

        if (ans > 9) {
            if (mn1 > mn2) {
                ans = mn2 * 10 + mn1;
            } else {
                ans = mn1 * 10 + mn2;
            }
        }

        return ans;
    }
}
