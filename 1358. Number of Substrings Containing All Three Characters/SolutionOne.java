
public class SolutionOne {

    public int numberOfSubstrings(String s) {
        final int len = s.length();

        int ans = 0;

        int[] freq = new int[3];
        int left = 0, right = 0;

        while (right < len) {
            freq[s.charAt(right) - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans += len - right;

                freq[s.charAt(left) - 'a']--;
                left++;
            }

            right++;
        }

        return ans;
    }
}
