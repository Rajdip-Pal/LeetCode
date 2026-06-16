
public class Solution {

    public int maxNumberOfBalloons(String text) {
        int[] frequency = new int[26];

        for (int i = 0; i < text.length(); i++) {
            final int idx = text.charAt(i) - 'a';
            frequency[idx]++;
        }

        int ans = text.length();
        String s = "balloon";

        for (int i = 0; i < s.length(); i++) {
            final int idx = s.charAt(i) - 'a';

            if (frequency[idx] == 0) {
                return 0;
            }

            if ((idx == 'l' - 'a' || idx == 'o' - 'a') && frequency[idx] < 2) {
                return 0;
            }

            ans = Math.min(ans, (idx == 'l' - 'a' || idx == 'o' - 'a') ? frequency[idx] / 2 : frequency[idx]);
        }

        return ans;
    }
}
